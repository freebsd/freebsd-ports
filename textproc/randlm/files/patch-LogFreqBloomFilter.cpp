--- src/RandLM/LogFreqBloomFilter.cpp.orig	2017-03-07 00:13:45 UTC
+++ src/RandLM/LogFreqBloomFilter.cpp
@@ -207,7 +207,7 @@ namespace randlm {
 
   int LogFreqBloomFilter::getMaxHashes(int event_idx) {
     // simple for unary encoding
-    assert(max_alpha_ > 0 && max_k_ > 0 && max_code_ > 0);
+	assert(max_alpha_ > 0 && max_k_ > 0 && max_code_ != NULL);
     return max_alpha_ + (max_k_ * max_code_[event_idx]);
   }
 
