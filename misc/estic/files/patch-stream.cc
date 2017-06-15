--- spunk/stream.cc.orig	1996-12-18 12:09:02 UTC
+++ spunk/stream.cc
@@ -347,7 +347,7 @@ void Stream::Write (const void*, size_t)
 
 void Stream::CopyFrom (Stream& S, size_t Count)
 {
-    static const BufSize = 4096;            // Size of copy buffer
+    static const int BufSize = 4096;            // Size of copy buffer
 
 
     // Check parameter
