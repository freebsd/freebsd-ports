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
