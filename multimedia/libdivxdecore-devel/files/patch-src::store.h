--- src/store.h.orig	Mon Sep 24 14:37:09 2001
+++ src/store.h	Mon Sep 24 14:37:16 2001
@@ -36,4 +36,4 @@
 
 /*** *** ***/
 
-extern void storeframe (unsigned char *src[], int xsize, int ysize);
+extern void storeframe (char * outputname, unsigned char *src[], int xsize, int ysize, int hor_stride);
