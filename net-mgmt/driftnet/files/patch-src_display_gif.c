--- src/display/gif.c.orig	2014-09-14 19:16:31 UTC
+++ src/display/gif.c
@@ -25,12 +25,7 @@
 int gif_load_hdr(img I) {
     GifFileType *g;
 
-/* GIFLIB_MAJOR is not defined until version 5 of libgif */
-#if defined GIFLIB_MAJOR && GIFLIB_MAJOR >= 5
     g = I->us = DGifOpenFileHandle(fileno(I->fp), NULL);
-#else
-    g = I->us = DGifOpenFileHandle(fileno(I->fp));
-#endif
 
     if (!I->us) {
         I->err = IE_HDRFORMAT;
@@ -47,7 +42,7 @@ int gif_load_hdr(img I) {
  * Abort loading a GIF file after the header is done.
  */
 int gif_abort_load(img I) {
-    DGifCloseFile((GifFileType*)I->us);
+    DGifCloseFile((GifFileType*)I->us, NULL);
     return 1;
 }
 
@@ -125,7 +120,7 @@ int gif_load_img(img I) {
     ret = 1;
 fail:
 
-    DGifCloseFile(g);
+    DGifCloseFile(g, NULL);
 
     return ret;
 }
