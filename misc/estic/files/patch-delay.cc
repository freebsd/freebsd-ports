--- spunk/unixsrc/delay.cc.orig	1996-11-07 17:06:58 UTC
+++ spunk/unixsrc/delay.cc
@@ -73,7 +73,7 @@ u32 Delay (u32 ms)
 //
 // The function returns the real time passed or just ms.
 {
-    const ChunkSize = 256;
+    const int ChunkSize = 256;
 
     // Check the argument...
     if (ms <= ChunkSize) {
