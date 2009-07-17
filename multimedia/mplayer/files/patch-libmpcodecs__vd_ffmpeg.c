--- ./libmpcodecs/vd_ffmpeg.c.orig	2007-10-07 15:49:25.000000000 -0400
+++ ./libmpcodecs/vd_ffmpeg.c	2009-07-17 14:28:08.733520971 -0400
@@ -387,7 +387,7 @@
     }
     /* Pass palette to codec */
     if (sh->bih && (sh->bih->biBitCount <= 8)) {
-        avctx->palctrl = calloc(1,sizeof(AVPaletteControl));
+        avctx->palctrl = av_malloc(sizeof(AVPaletteControl));
         avctx->palctrl->palette_changed = 1;
         if (sh->bih->biSize-sizeof(BITMAPINFOHEADER))
             /* Palette size in biSize */
