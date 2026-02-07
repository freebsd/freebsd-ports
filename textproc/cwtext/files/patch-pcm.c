--- pcm.c.orig	2008-01-07 15:26:50 UTC
+++ pcm.c
@@ -60,7 +60,7 @@ int mStoSamples(int hVox, int time) {
   float samples;
   float fsr;
   
-  if (!valid(hVox)) return;
+  if (!valid(hVox)) return(0);
 
   timelen = (float) time;
   fsr = (float) voxref(hVox).samplerate;
