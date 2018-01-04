--- src/RandLM/BloomMap.cpp.orig	2017-03-07 00:13:58 UTC
+++ src/RandLM/BloomMap.cpp
@@ -272,7 +272,7 @@ namespace randlm {
   
   bool BloomMap::computePaths() {
     // determine the path lengths based on distribution for codes of each type
-    assert(stats_counters_ && root_ == NULL && max_code_ > 0);
+    assert(stats_counters_ && root_ == NULL && max_code_  != NULL);
     code_to_leaf_ = new uint64_t*[num_events_];
     code_to_path_len_ = new int*[num_events_];
     code_to_bound_ = new int*[num_events_];
