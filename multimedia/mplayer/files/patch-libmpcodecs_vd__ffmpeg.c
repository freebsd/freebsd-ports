--- libmpcodecs/vd_ffmpeg.c.orig	2022-08-07 18:20:47 UTC
+++ libmpcodecs/vd_ffmpeg.c
@@ -739,7 +739,7 @@ static int get_buffer(AVCodecContext *avctx, AVFrame *
     if (ctx->use_vdpau) {
         VdpVideoSurface surface = (VdpVideoSurface)mpi->priv;
         avctx->draw_horiz_band= NULL;
-        mpi->planes[3] = surface;
+        mpi->planes[3] = (unsigned char*)surface;
     }
 #endif
 #if CONFIG_XVMC
