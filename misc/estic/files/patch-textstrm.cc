--- spunk/textstrm.cc.orig	1996-11-07 17:06:52 UTC
+++ spunk/textstrm.cc
@@ -66,8 +66,8 @@ void TextFileStream::MakeLineIndex (int 
 // LineLen is the estimated length of a line in the file used for
 // estimating the size of the buffer.
 {
-    static const Delta   = 100;
-    static const BufSize = 4096;
+    static const int Delta   = 100;
+    static const int BufSize = 4096;
 
     // Estimate the count of lines
     if ((Limit = Size / LineLen) < 100) {
