--- libmpcodecs/vd_ffmpeg.c.orig	2011-02-05 15:02:49.000000000 +0100
+++ libmpcodecs/vd_ffmpeg.c	2011-03-24 19:10:08.064575435 +0100
@@ -423,7 +423,7 @@
     }
     /* Pass palette to codec */
     if (sh->bih && (sh->bih->biBitCount <= 8)) {
-        avctx->palctrl = calloc(1, sizeof(AVPaletteControl));
+        avctx->palctrl = av_malloc(sizeof(AVPaletteControl));
         avctx->palctrl->palette_changed = 1;
         if (sh->bih->biSize-sizeof(*sh->bih))
             /* Palette size in biSize */
