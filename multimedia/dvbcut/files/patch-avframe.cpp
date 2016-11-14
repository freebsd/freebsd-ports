--- src/avframe.cpp.orig	2016-06-23 12:34:35 UTC
+++ src/avframe.cpp
@@ -52,7 +52,7 @@ avframe::avframe(AVFrame *src, AVCodecCo
   tobefreed = (uint8_t *)malloc(avpicture_get_size(ctx->pix_fmt, ctx->width, ctx->height));
 
   avpicture_fill((AVPicture *)f,
-                 (u_int8_t*)tobefreed,
+                 (uint8_t*)tobefreed,
                  ctx->pix_fmt,ctx->width,ctx->height);
 
   av_picture_copy((AVPicture *)f, (const AVPicture *) src,
