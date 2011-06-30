--- pcm.c.orig	2011-06-30 18:51:13.000000000 -0400
+++ pcm.c	2011-06-30 18:51:47.000000000 -0400
@@ -60,7 +60,7 @@
   float samples;
   float fsr;
   
-  if (!valid(hVox)) return;
+  if (!valid(hVox)) return(0);
 
   timelen = (float) time;
   fsr = (float) voxref(hVox).samplerate;
