--- src/RandLM/RandLM.h.orig	2012-03-30 13:53:30.000000000 +0400
+++ src/RandLM/RandLM.h	2014-09-01 18:11:00.000000000 +0400
@@ -86,8 +86,8 @@ namespace randlm {
 
     static const std::string kRandLMFileType;
 
-    static const float kNullLogProb = -1000000;
-    static const float kUnknownLogProb = 1000000;
+    static constexpr float kNullLogProb = -1000000;
+    static constexpr float kUnknownLogProb = 1000000;
 
     static const int kMainEventIdx = 0;
     static const int kAuxEventIdx = 1;
