--- src/RandLM/LogFreqSketch.cpp.orig	2012-03-30 13:53:30.000000000 +0400
+++ src/RandLM/LogFreqSketch.cpp	2014-09-01 18:22:05.000000000 +0400
@@ -162,7 +162,7 @@ namespace randlm {
 
   bool LogFreqSketch::load(RandLMFile* fin) {
     // just maximum m 
-    return fin->read((char*)&maximum_m_, sizeof(maximum_m_));;
+    return fin->read((char*)&maximum_m_, sizeof(maximum_m_)).good();
   }
 
   bool LogFreqSketch::save(RandLMFile* fout) {
@@ -170,7 +170,7 @@ namespace randlm {
     assert(LogFreqBloomFilter::save(fout));  // saves RandLMStruct first
     assert(OnlineRandLMStruct::save(fout));
     // just maximum m
-    return fout->write((char*)&maximum_m_, sizeof(maximum_m_));;
+    return fout->write((char*)&maximum_m_, sizeof(maximum_m_)).good();
   }
 
 }
