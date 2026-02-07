--- src/lm/LabelManagerDriver.cpp.orig	2012-02-07 13:22:38 UTC
+++ src/lm/LabelManagerDriver.cpp
@@ -152,12 +152,12 @@ void 
 CLabelManagerDriver::GetBlanks(
   const buffer_t& Buf, size_t& LeaderBlanks, size_t& TrailerBlanks)
 {
-  size_t i = 0;
+  ssize_t i = 0;
 
   LeaderBlanks    = 0;
   TrailerBlanks   = 0;
 
-  size_t BufSize = Buf.size();
+  ssize_t BufSize = Buf.size();
 
   // count left spaces 
   for (i = 0; i < BufSize; ++i)
