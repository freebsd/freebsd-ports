--- src/lw/LabelWriterDriver.cpp.orig	2012-02-07 13:22:37 UTC
+++ src/lw/LabelWriterDriver.cpp
@@ -121,12 +121,12 @@ void
 CLabelWriterDriver::GetBlanks(
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
