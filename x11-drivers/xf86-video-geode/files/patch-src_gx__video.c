--- src/gx_video.c.orig	2020-08-24 18:14:49 UTC
+++ src/gx_video.c
@@ -112,7 +112,7 @@ void GXSetVideoPosition(int x, int y, int width, int h
 
 extern void GXAccelSync(ScrnInfoPtr pScrni);
 
-int DeltaX, DeltaY;
+extern int DeltaX, DeltaY;
 
 unsigned long graphics_lut[256];
 static int lutflag = 0;
