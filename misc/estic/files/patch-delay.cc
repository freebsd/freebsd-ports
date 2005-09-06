--- spunk/unixsrc/delay.cc.orig	Sat Feb 26 17:50:13 2000
+++ spunk/unixsrc/delay.cc	Sat Feb 26 17:50:24 2000
@@ -73,7 +73,7 @@
 //
 // The function returns the real time passed or just ms.
 {
-    const ChunkSize = 256;
+    const int ChunkSize = 256;
 
     // Check the argument...
     if (ms <= ChunkSize) {
