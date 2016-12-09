--- screenshot.c.orig	2013-07-09 16:33:27 UTC
+++ screenshot.c
@@ -57,7 +57,7 @@ static int destroy_ctx(void *ptr)
 {
     struct screenshot_ctx *ctx = ptr;
 #if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(54, 28, 0)
-    avcodec_free_frame(&ctx->pic);
+    av_frame_free(&ctx->pic);
 #else
     av_free(ctx->pic);
 #endif
@@ -69,7 +69,7 @@ static screenshot_ctx *screenshot_get_ct
     if (!mpctx->screenshot_ctx) {
         struct screenshot_ctx *ctx = talloc_zero(mpctx, screenshot_ctx);
         talloc_set_destructor(ctx, destroy_ctx);
-        ctx->pic = avcodec_alloc_frame();
+        ctx->pic = av_frame_alloc();
         assert(ctx->pic);
         mpctx->screenshot_ctx = ctx;
     }
@@ -80,8 +80,12 @@ static int write_png(screenshot_ctx *ctx
 {
     char *fname = ctx->fname;
     FILE *fp = NULL;
-    void *outbuffer = NULL;
     int success = 0;
+    int got_pkt;
+    AVPacket pkt = {0};
+    int got_output = 0;
+
+    av_init_packet(&pkt);

     struct AVCodec *png_codec = avcodec_find_encoder(AV_CODEC_ID_PNG);
     AVCodecContext *avctx = NULL;
@@ -94,7 +98,7 @@ static int write_png(screenshot_ctx *ctx
     avctx->time_base = AV_TIME_BASE_Q;
     avctx->width = image->width;
     avctx->height = image->height;
-    avctx->pix_fmt = PIX_FMT_RGB24;
+    avctx->pix_fmt = AV_PIX_FMT_RGB24;
     avctx->compression_level = 0;

     if (avcodec_open2(avctx, png_codec, NULL) < 0) {
@@ -104,19 +108,14 @@ static int write_png(screenshot_ctx *ctx
         goto error_exit;
     }

-    size_t outbuffer_size = image->width * image->height * 3 * 2;
-    outbuffer = malloc(outbuffer_size);
-    if (!outbuffer)
-        goto error_exit;
-
     AVFrame *pic = ctx->pic;
-    avcodec_get_frame_defaults(pic);
+    av_frame_unref(pic);
     for (int n = 0; n < 4; n++) {
         pic->data[n] = image->planes[n];
         pic->linesize[n] = image->stride[n];
     }
-    int size = avcodec_encode_video(avctx, outbuffer, outbuffer_size, pic);
-    if (size < 1)
+    int ret = avcodec_encode_video2(avctx, &pkt, pic, &got_output);
+    if (ret < 0)
         goto error_exit;

     fp = fopen(fname, "wb");
@@ -126,20 +125,20 @@ static int write_png(screenshot_ctx *ctx
         goto error_exit;
     }

-    fwrite(outbuffer, size, 1, fp);
+    fwrite(pkt.data, pkt.size, 1, fp);
     fflush(fp);

     if (ferror(fp))
         goto error_exit;

-    success = 1;
+    success = !!got_output;
 error_exit:
     if (avctx)
         avcodec_close(avctx);
     av_free(avctx);
     if (fp)
         fclose(fp);
-    free(outbuffer);
+    av_free_packet(&pkt);
     return success;
 }

