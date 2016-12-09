--- libmpcodecs/vd_ffmpeg.c.orig	2013-07-09 16:33:13 UTC
+++ libmpcodecs/vd_ffmpeg.c
@@ -25,6 +25,7 @@
 #include <libavutil/common.h>
 #include <libavutil/opt.h>
 #include <libavutil/intreadwrite.h>
+#include <libavutil/pixdesc.h>

 #include "talloc.h"
 #include "config.h"
@@ -61,7 +62,7 @@ static const vd_info_t info = {
 typedef struct {
     AVCodecContext *avctx;
     AVFrame *pic;
-    enum PixelFormat pix_fmt;
+    enum AVPixelFormat pix_fmt;
     int do_slices;
     int do_dr1;
     int vo_initialized;
@@ -77,13 +78,16 @@ typedef struct {

 #include "m_option.h"

-static int get_buffer(AVCodecContext *avctx, AVFrame *pic);
+static int get_buffer(AVCodecContext *avctx, AVFrame *pic, int isreference);
+static int mpcodec_default_get_buffer(AVCodecContext *avctx, AVFrame *frame);
+static int get_buffer2(AVCodecContext *avctx, AVFrame *frame, int flags);
 static void release_buffer(AVCodecContext *avctx, AVFrame *pic);
+static void mpcodec_default_release_buffer(AVCodecContext *s, AVFrame *pic);
 static void draw_slice(struct AVCodecContext *s, const AVFrame *src,
                        int offset[4], int y, int type, int height);

-static enum PixelFormat get_format(struct AVCodecContext *avctx,
-                                   const enum PixelFormat *pix_fmt);
+static enum AVPixelFormat get_format(struct AVCodecContext *avctx,
+                                   const enum AVPixelFormat *pix_fmt);
 static void uninit(struct sh_video *sh);

 const m_option_t lavc_decode_opts_conf[] = {
@@ -169,7 +173,7 @@ static int init(sh_video_t *sh)
         ctx->do_dr1 = 1;
     ctx->ip_count = ctx->b_count = 0;

-    ctx->pic = avcodec_alloc_frame();
+    ctx->pic = av_frame_alloc();
     ctx->avctx = avcodec_alloc_context3(lavc_codec);
     avctx = ctx->avctx;
     avctx->opaque = sh;
@@ -182,9 +186,7 @@ static int init(sh_video_t *sh)
         ctx->do_slices = true;
         lavc_param->threads    = 1;
         avctx->get_format      = get_format;
-        avctx->get_buffer      = get_buffer;
-        avctx->release_buffer  = release_buffer;
-        avctx->reget_buffer    = get_buffer;
+        avctx->get_buffer2      = get_buffer2;
         avctx->draw_horiz_band = draw_slice;
         if (lavc_codec->capabilities & CODEC_CAP_HWACCEL_VDPAU)
             mp_msg(MSGT_DECVIDEO, MSGL_V, "[VD_FFMPEG] VDPAU hardware "
@@ -212,10 +214,7 @@ static int init(sh_video_t *sh)
     }

     if (ctx->do_dr1) {
-        avctx->flags |= CODEC_FLAG_EMU_EDGE;
-        avctx->get_buffer = get_buffer;
-        avctx->release_buffer = release_buffer;
-        avctx->reget_buffer = get_buffer;
+        avctx->get_buffer2 = get_buffer2;
     }

     avctx->flags |= lavc_param->bitexact;
@@ -227,7 +226,6 @@ static int init(sh_video_t *sh)
         avctx->flags |= CODEC_FLAG_GRAY;
     avctx->flags2 |= lavc_param->fast;
     avctx->codec_tag = sh->format;
-    avctx->stream_codec_tag = sh->video.fccHandler;
     avctx->idct_algo = lavc_param->idct_algo;
     avctx->error_concealment = lavc_param->error_concealment;
     avctx->debug = lavc_param->debug;
@@ -357,7 +355,7 @@ static void uninit(sh_video_t *sh)

     av_freep(&avctx);
 #if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(54, 28, 0)
-    avcodec_free_frame(&ctx->pic);
+    av_frame_free(&ctx->pic);
 #else
     av_freep(&ctx->pic);
 #endif
@@ -423,7 +421,7 @@ static enum mp_csp_levels avcol_range_to
     }
 }

-static int init_vo(sh_video_t *sh, enum PixelFormat pix_fmt)
+static int init_vo(sh_video_t *sh, enum AVPixelFormat pix_fmt)
 {
     vd_ffmpeg_ctx *ctx = sh->context;
     AVCodecContext *avctx = ctx->avctx;
@@ -488,7 +486,7 @@ static int init_vo(sh_video_t *sh, enum
     return 0;
 }

-static int get_buffer(AVCodecContext *avctx, AVFrame *pic)
+static int get_buffer(AVCodecContext *avctx, AVFrame *pic, int isreference)
 {
     sh_video_t *sh = avctx->opaque;
     vd_ffmpeg_ctx *ctx = sh->context;
@@ -499,29 +497,11 @@ static int get_buffer(AVCodecContext *av
     int width = avctx->width;
     int height = avctx->height;
     // special case to handle reget_buffer without buffer hints
-    if (pic->opaque && pic->data[0] && !pic->buffer_hints)
+    if (pic->opaque && pic->data[0])
         return 0;
     avcodec_align_dimensions(avctx, &width, &height);

-    if (pic->buffer_hints) {
-        mp_msg(MSGT_DECVIDEO, MSGL_DBG2, "Buffer hints: %u\n",
-               pic->buffer_hints);
-        type = MP_IMGTYPE_TEMP;
-        if (pic->buffer_hints & FF_BUFFER_HINTS_READABLE)
-            flags |= MP_IMGFLAG_READABLE;
-        if (pic->buffer_hints & FF_BUFFER_HINTS_PRESERVE) {
-            type = MP_IMGTYPE_STATIC;
-            flags |= MP_IMGFLAG_PRESERVE;
-        }
-        if (pic->buffer_hints & FF_BUFFER_HINTS_REUSABLE) {
-            type = MP_IMGTYPE_STATIC;
-            flags |= MP_IMGFLAG_PRESERVE;
-        }
-        flags |= ctx->do_slices ? MP_IMGFLAG_DRAW_CALLBACK : 0;
-        mp_msg(MSGT_DECVIDEO, MSGL_DBG2,
-               type == MP_IMGTYPE_STATIC ? "using STATIC\n" : "using TEMP\n");
-    } else {
-        if (!pic->reference) {
+        if (!isreference) {
             ctx->b_count++;
             flags |= ctx->do_slices ? MP_IMGFLAG_DRAW_CALLBACK : 0;
         } else {
@@ -529,29 +509,25 @@ static int get_buffer(AVCodecContext *av
             flags |= MP_IMGFLAG_PRESERVE | MP_IMGFLAG_READABLE
                      | (ctx->do_slices ? MP_IMGFLAG_DRAW_CALLBACK : 0);
         }
-    }

     if (init_vo(sh, avctx->pix_fmt) < 0) {
-        avctx->release_buffer = avcodec_default_release_buffer;
-        avctx->get_buffer = avcodec_default_get_buffer;
-        avctx->reget_buffer = avcodec_default_reget_buffer;
+        avctx->get_buffer2 = avcodec_default_get_buffer2;
         if (pic->data[0])
-            release_buffer(avctx, pic);
-        return avctx->get_buffer(avctx, pic);
+            mpcodec_default_release_buffer(avctx, pic);
+        return avctx->get_buffer2(avctx, pic,0);
     }

     if (IMGFMT_IS_HWACCEL(ctx->best_csp))
         type =  MP_IMGTYPE_NUMBERED | (0xffff << 16);
-    else if (!pic->buffer_hints) {
+    else {
         if (ctx->b_count > 1 || ctx->ip_count > 2) {
             mp_tmsg(MSGT_DECVIDEO, MSGL_WARN, "[VD_FFMPEG] DRI failure.\n");

             ctx->do_dr1 = 0; //FIXME
-            avctx->get_buffer = avcodec_default_get_buffer;
-            avctx->reget_buffer = avcodec_default_reget_buffer;
+            avctx->get_buffer2 = avcodec_default_get_buffer2;
             if (pic->data[0])
-                release_buffer(avctx, pic);
-            return avctx->get_buffer(avctx, pic);
+                mpcodec_default_release_buffer(avctx, pic);
+            return avctx->get_buffer2(avctx, pic,0);
         }

         if (avctx->has_b_frames || ctx->b_count)
@@ -594,7 +570,6 @@ static int get_buffer(AVCodecContext *av

     pic->opaque = mpi;

-    pic->type = FF_BUFFER_TYPE_USER;

     /* The libavcodec reordered_opaque functionality is implemented by
      * a similar copy in avcodec_default_get_buffer() and without a
@@ -626,8 +601,8 @@ static void release_buffer(struct AVCode
         mpi->usage_count--;
     }

-    if (pic->type != FF_BUFFER_TYPE_USER) {
-        avcodec_default_release_buffer(avctx, pic);
+    if (pic->opaque == NULL) {
+        mpcodec_default_release_buffer(avctx, pic);
         return;
     }

@@ -822,13 +797,13 @@ static struct mp_image *decode(struct sh
     return mpi;
 }

-static enum PixelFormat get_format(struct AVCodecContext *avctx,
-                                   const enum PixelFormat *fmt)
+static enum AVPixelFormat get_format(struct AVCodecContext *avctx,
+                                   const enum AVPixelFormat *fmt)
 {
     sh_video_t *sh = avctx->opaque;
     int i;

-    for (i = 0; fmt[i] != PIX_FMT_NONE; i++) {
+    for (i = 0; fmt[i] != AV_PIX_FMT_NONE; i++) {
         int imgfmt = pixfmt2imgfmt(fmt[i]);
         if (!IMGFMT_IS_HWACCEL(imgfmt))
             continue;
@@ -886,3 +861,144 @@ const struct vd_functions mpcodecs_vd_ff
     .control = control,
     .decode2 = decode
 };
+
+/*
+FFWrapper
+*/
+static int mpcodec_default_get_buffer(AVCodecContext *avctx, AVFrame *frame)
+{
+    return avcodec_default_get_buffer2(avctx, frame, 0);
+}
+
+static void mpcodec_default_release_buffer(AVCodecContext *s, AVFrame *pic)
+{
+    av_frame_unref(pic);
+}
+
+typedef struct CompatReleaseBufPriv {
+    AVCodecContext avctx;
+    AVFrame frame;
+    uint8_t avframe_padding[1024]; // hack to allow linking to a avutil larger AVFrame
+} CompatReleaseBufPriv;
+
+static void compat_free_buffer(void *opaque, uint8_t *data)
+{
+    CompatReleaseBufPriv *priv = opaque;
+    release_buffer(&priv->avctx, &priv->frame);
+    av_freep(&priv);
+}
+
+static void compat_release_buffer(void *opaque, uint8_t *data)
+{
+    AVBufferRef *buf = opaque;
+    av_buffer_unref(&buf);
+}
+
+static int get_buffer2(AVCodecContext *avctx, AVFrame *frame, int flags)
+{
+    /*
+     * Wrap an old get_buffer()-allocated buffer in a bunch of AVBuffers.
+     * We wrap each plane in its own AVBuffer. Each of those has a reference to
+     * a dummy AVBuffer as its private data, unreffing it on free,
+     * When all the planes are freed, the dummy buffer's free callback calls
+     * release_buffer().
+     */
+    CompatReleaseBufPriv *priv = NULL;
+    AVBufferRef *dummy_buf = NULL;
+    int planes, i, ret;
+
+    ret = get_buffer(avctx, frame, flags & AV_GET_BUFFER_FLAG_REF);
+    if (ret < 0)
+        return ret;
+
+    /* return if the buffers are already set up
+     * this would happen e.g. when a custom get_buffer() calls
+     * avcodec_default_get_buffer
+     */
+    if (frame->buf[0])
+       goto end0;
+
+    priv = av_mallocz(sizeof(*priv));
+    if (!priv) {
+        ret = AVERROR(ENOMEM);
+        goto fail;
+    }
+    priv->avctx = *avctx;
+    priv->frame = *frame;
+
+    dummy_buf = av_buffer_create(NULL, 0, compat_free_buffer, priv, 0);
+    if (!dummy_buf) {
+        ret = AVERROR(ENOMEM);
+        goto fail;
+    }
+
+#define WRAP_PLANE(ref_out, data, data_size)                            \
+do {                                                                    \
+    AVBufferRef *dummy_ref = av_buffer_ref(dummy_buf);                  \
+    if (!dummy_ref) {                                                   \
+        ret = AVERROR(ENOMEM);                                          \
+        goto fail;                                                      \
+    }                                                                   \
+    ref_out = av_buffer_create(data, data_size, compat_release_buffer,  \
+                               dummy_ref, 0);                           \
+    if (!ref_out) {                                                     \
+        av_buffer_unref(&dummy_ref);                                    \
+        av_frame_unref(frame);                                          \
+        ret = AVERROR(ENOMEM);                                          \
+        goto fail;                                                      \
+    }                                                                   \
+} while (0)
+
+    if (avctx->codec_type == AVMEDIA_TYPE_VIDEO) {
+        const AVPixFmtDescriptor *desc = av_pix_fmt_desc_get(frame->format);
+
+        planes = av_pix_fmt_count_planes(frame->format);
+        /* workaround for AVHWAccel plane count of 0, buf[0] is used as
+           check for allocated buffers: make libavcodec happy */
+        if (desc && desc->flags & AV_PIX_FMT_FLAG_HWACCEL)
+            planes = 1;
+        if (!desc || planes <= 0) {
+            ret = AVERROR(EINVAL);
+            goto fail;
+        }
+
+        for (i = 0; i < planes; i++) {
+            int v_shift    = (i == 1 || i == 2) ? desc->log2_chroma_h : 0;
+            int plane_size = (frame->height >> v_shift) * frame->linesize[i];
+
+            WRAP_PLANE(frame->buf[i], frame->data[i], plane_size);
+        }
+    } else {
+        int planar = av_sample_fmt_is_planar(frame->format);
+        planes = planar ? avctx->channels : 1;
+
+        if (planes > FF_ARRAY_ELEMS(frame->buf)) {
+            frame->nb_extended_buf = planes - FF_ARRAY_ELEMS(frame->buf);
+            frame->extended_buf = av_malloc_array(sizeof(*frame->extended_buf),
+                                            frame->nb_extended_buf);
+            if (!frame->extended_buf) {
+                ret = AVERROR(ENOMEM);
+                goto fail;
+            }
+         }
+
+         for (i = 0; i < FFMIN(planes, FF_ARRAY_ELEMS(frame->buf)); i++)
+             WRAP_PLANE(frame->extended_buf[i],
+                        frame->extended_data[i + FF_ARRAY_ELEMS(frame->buf)],
+                        frame->linesize[0]);
+    }
+
+    av_buffer_unref(&dummy_buf);
+
+end0:
+    frame->width  = avctx->width;
+    frame->height = avctx->height;
+
+    return 0;
+
+fail:
+    release_buffer(avctx, frame);
+    av_freep(&priv);
+    av_buffer_unref(&dummy_buf);
+    return ret;
+}
