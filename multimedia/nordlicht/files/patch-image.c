For ffmpeg 3.x compatibility

https://github.com/nordlicht/nordlicht/commit/5505a1898ab997a23b75553794eff6609447c43b.patch
https://github.com/nordlicht/nordlicht/commit/6e534a0c273756b88eecea7f510b6aa8a62dd789.patch
and https://github.com/nordlicht/nordlicht/pull/63/commits/b8f439c2796d6b1de73511c0610aecb31c942790

--- image.c.orig	2016-01-24 19:35:50 UTC
+++ image.c
@@ -5,11 +5,36 @@
 #include <string.h>
 #include <libswscale/swscale.h>
 
+// Changes for ffmpeg 3.0
+#if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(57,24,0)
+#  include <libavutil/imgutils.h>
+#  define av_free_packet av_packet_unref
+#  define avpicture_get_size(fmt,w,h) av_image_get_buffer_size(fmt,w,h,1)
+#endif
+
+// PIX_FMT was renamed to AV_PIX_FMT on this version
+#if LIBAVUTIL_VERSION_INT < AV_VERSION_INT(51,74,100)
+#  define AVPixelFormat PixelFormat
+#  define AV_PIX_FMT_RGB24 PIX_FMT_RGB24
+#  define AV_PIX_FMT_YUVJ420P PIX_FMT_YUVJ420P
+#  define AV_PIX_FMT_YUVJ422P PIX_FMT_YUVJ422P
+#  define AV_PIX_FMT_YUVJ440P PIX_FMT_YUVJ440P
+#  define AV_PIX_FMT_YUVJ444P PIX_FMT_YUVJ444P
+#  define AV_PIX_FMT_YUV420P  PIX_FMT_YUV420P
+#  define AV_PIX_FMT_YUV422P  PIX_FMT_YUV422P
+#  define AV_PIX_FMT_YUV440P  PIX_FMT_YUV440P
+#  define AV_PIX_FMT_YUV444P  PIX_FMT_YUV444P
+#endif
+
 #if LIBAVUTIL_VERSION_INT < AV_VERSION_INT(52, 8, 0)
-#define av_frame_alloc  avcodec_alloc_frame
-#define av_frame_free av_freep
+#  define av_frame_alloc  avcodec_alloc_frame
+#  if LIBAVCODEC_VERSION_INT < AV_VERSION_INT(54,59,100)
+#    define av_frame_free   av_freep
+#  else
+#    define av_frame_free   avcodec_free_frame
+#  endif
 void av_frame_get_buffer(AVFrame *frame, int magic) { avpicture_alloc((AVPicture *)frame, frame->format, frame->width, frame->height); }
-void av_frame_copy(AVFrame *dst, AVFrame *src) { memcpy(dst->data[0], src->data[0], sizeof(uint8_t)*avpicture_get_size(PIX_FMT_RGB24, dst->width, dst->height)); }
+void av_frame_copy(AVFrame *dst, AVFrame *src) { memcpy(dst->data[0], src->data[0], sizeof(uint8_t)*avpicture_get_size(AV_PIX_FMT_RGB24, dst->width, dst->height)); }
 #endif
 
 #define MAX_FILTER_SIZE 256
@@ -25,7 +50,7 @@ image *image_init(const int width, const
     i->frame = (AVFrame *) av_frame_alloc();
     i->frame->width = width;
     i->frame->height = height;
-    i->frame->format = PIX_FMT_RGB24; // best choice?
+    i->frame->format = AV_PIX_FMT_RGB24; // best choice?
     av_frame_get_buffer(i->frame, 16); // magic number?
     return i;
 }
@@ -240,7 +265,9 @@ int image_write_png(const image *i, cons
     encoder_context = avcodec_alloc_context3(encoder);
     encoder_context->width = i->frame->width;
     encoder_context->height = i->frame->height;
-    encoder_context->pix_fmt = PIX_FMT_RGB24;
+    encoder_context->pix_fmt = AV_PIX_FMT_RGB24;
+    encoder_context->time_base.num = 1;
+    encoder_context->time_base.den = 1;
     if (avcodec_open2(encoder_context, encoder, NULL) < 0) {
         error("Could not open output codec.");
         return -1;
