--- spunk/textstrm.cc.orig	Sat Feb 26 18:05:06 2000
+++ spunk/textstrm.cc	Sat Feb 26 18:05:17 2000
@@ -66,8 +66,8 @@
 // LineLen is the estimated length of a line in the file used for
 // estimating the size of the buffer.
 {
-    static const Delta   = 100;
-    static const BufSize = 4096;
+    static const int Delta   = 100;
+    static const int BufSize = 4096;
 
     // Estimate the count of lines
     if ((Limit = Size / LineLen) < 100) {
