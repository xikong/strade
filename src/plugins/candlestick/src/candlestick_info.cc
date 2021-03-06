/*
 * candlestick_info.cc
 *
 *  Created on: 2017年1月9日
 *      Author: panghao
 */
#include "src/candlestick_info.h"
#include "string.h"
#include <stdio.h>
namespace candlestick {
StockDealInfo::StockDealInfo() : amount_(0), date_("1900-00-00") {
}

StockDealInfo::~StockDealInfo() {
}

void StockDealInfo::StatStockDealInfo(const StockDealInfo &info) {
  amount_ += info.amount_;
  printf("add %ld\n", info.amount_);
  // 日期更新至最后一天 字典顺序
  if (strncmp(date_.c_str(), info.date_.c_str(), date_.length()) < 0) {
     date_ = info.date_;
  }
}

SingleStockInfo::SingleStockInfo()
    : high_price_(0),
      low_price_(0),
      open_price_(0),
      close_price_(0) {
}

SingleStockInfo::~SingleStockInfo() {
}

void SingleStockInfo::StatSingleStockInfo(const SingleStockInfo &info) {
  if (low_price_ > info.low_price_) {
    low_price_ = info.low_price_;
  }
  if (high_price_ < info.high_price_) {
    high_price_ = info.high_price_;
  }
  StockDealInfo::StatStockDealInfo(info);
  printf("%s  %d\n", __FILE__, __LINE__);
}

CompositeindexInfo::CompositeindexInfo()
    : high_index_(0),
      low_index_(0),
      open_index_(0),
      close_index_(0) {
}

CompositeindexInfo::~CompositeindexInfo() {
}

void CompositeindexInfo::StatCompositeindexInfo(const CompositeindexInfo &info) {
  if (low_index_ > info.low_index_) {
    low_index_ = info.low_index_;
  }
  if (high_index_ < info.high_index_) {
    high_index_ = info.high_index_;
  }
  StockDealInfo::StatStockDealInfo(info);
}

}  // namespace candlestick

