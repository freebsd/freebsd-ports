--- src/display/gif.c.orig	2013-05-12 15:16:43 UTC
+++ src/display/gif.c
@@ -22,7 +22,7 @@
  */
 int gif_load_hdr(img I) {
     GifFileType *g;
-    g = I->us = DGifOpenFileHandle(fileno(I->fp));
+    g = I->us = DGifOpenFileHandle(fileno(I->fp), NULL);
     if (!I->us) {
         I->err = IE_HDRFORMAT;
         return 0;
@@ -38,7 +38,7 @@ int gif_load_hdr(img I) {
  * Abort loading a GIF file after the header is done.
  */
 int gif_abort_load(img I) {
-    DGifCloseFile((GifFileType*)I->us);
+    DGifCloseFile((GifFileType*)I->us, NULL);
     return 1;
 }
 
@@ -116,7 +116,7 @@ int gif_load_img(img I) {
     ret = 1;
 fail:
 
-    DGifCloseFile(g);
+    DGifCloseFile(g, NULL);
 
     return ret;
 }
