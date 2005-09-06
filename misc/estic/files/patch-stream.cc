--- spunk/stream.cc.orig	Sat Feb 26 18:03:19 2000
+++ spunk/stream.cc	Sat Feb 26 18:03:35 2000
@@ -245,7 +245,7 @@
 
 void Stream::CopyFrom (Stream& S, size_t Count)
 {
-    static const BufSize = 4096;            // Size of copy buffer
+    static const int BufSize = 4096;            // Size of copy buffer
 
 
     // Check parameter
