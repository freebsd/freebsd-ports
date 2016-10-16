--- cpp/server/log_processes.cc.orig	2016-10-14 17:11:57 UTC
+++ cpp/server/log_processes.cc
@@ -23,7 +23,7 @@ DEFINE_int32(cleanup_frequency_seconds, 
 using cert_trans::Counter;
 using cert_trans::Gauge;
 using cert_trans::Latency;
-using google::RegisterFlagValidator;
+using gflags::RegisterFlagValidator;
 using ct::SignedTreeHead;
 using std::function;
 using std::chrono::milliseconds;
