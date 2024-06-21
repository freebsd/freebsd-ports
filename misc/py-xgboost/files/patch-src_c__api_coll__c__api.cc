- workaround for https://github.com/dmlc/xgboost/issues/10466

--- ../src/c_api/coll_c_api.cc.orig	2024-06-21 07:43:36 UTC
+++ ../src/c_api/coll_c_api.cc
@@ -75,7 +75,7 @@ void WaitImpl(TrackerHandleT *ptr, std::chrono::second
 
 void WaitImpl(TrackerHandleT *ptr, std::chrono::seconds timeout) {
   constexpr std::int64_t kDft{collective::DefaultTimeoutSec()};
-  std::chrono::seconds wait_for{collective::HasTimeout(timeout) ? std::min(kDft, timeout.count())
+  std::chrono::seconds wait_for{collective::HasTimeout(timeout) ? std::min(long(kDft), long(timeout.count()))
                                                                 : kDft};
 
   common::Timer timer;
