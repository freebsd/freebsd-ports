--- modules/visualization/galaktos/PCM.c.orig	Fri Nov 26 08:21:47 2004
+++ modules/visualization/galaktos/PCM.c	Fri Nov 26 08:22:06 2004
@@ -79,7 +79,7 @@
 //Takes in a 2x512 array of PCM samples
 //and stores them
 
-void addPCM(int16_t PCMdata[2][512])
+void addPCM(short PCMdata[2][512])
 {
   int i,j;
   int samples=512;
