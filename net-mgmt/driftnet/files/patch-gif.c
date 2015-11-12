--- gif.c.orig	2002-07-09 19:26:41 UTC
+++ gif.c
@@ -20,7 +20,11 @@ static const char rcsid[] = "$Id: gif.c,
  */
 int gif_load_hdr(img I) {
     GifFileType *g;
+#if GIFLIB_MAJOR >= 5
+    g = I->us = DGifOpenFileHandle(fileno(I->fp), NULL);
+#else
     g = I->us = DGifOpenFileHandle(fileno(I->fp));
+#endif
     if (!I->us) {
         I->err = IE_HDRFORMAT;
         return 0;
@@ -36,7 +40,11 @@ int gif_load_hdr(img I) {
  * Abort loading a GIF file after the header is done.
  */
 int gif_abort_load(img I) {
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+    DGifCloseFile((GifFileType*)I->us, NULL);
+#else
     DGifCloseFile((GifFileType*)I->us);
+#endif
     return 1;
 }
 
@@ -114,7 +122,11 @@ int gif_load_img(img I) {
     ret = 1;
 fail:
 
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+    DGifCloseFile(g, NULL);
+#else
     DGifCloseFile(g);
+#endif
     
     return ret;
 }
