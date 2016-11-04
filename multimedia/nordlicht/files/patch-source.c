For ffmpeg 3.x compatibility

https://github.com/nordlicht/nordlicht/commit/5505a1898ab997a23b75553794eff6609447c43b.patch
https://github.com/nordlicht/nordlicht/commit/6e534a0c273756b88eecea7f510b6aa8a62dd789.patch

--- source.c.orig	2016-01-24 19:35:50 UTC
+++ source.c
@@ -6,9 +6,34 @@
 #include <libavutil/avutil.h>
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
 #endif
 
 #define HEURISTIC_NUMBER_OF_FRAMES 1800 // how many frames will the heuristic look at?
@@ -244,13 +269,17 @@ source* source_init(const char *filename
         s->scaleframe = av_frame_alloc();
         s->scaleframe->width = s->video->frame->width;
         s->scaleframe->height = s->video->frame->height;
-        s->scaleframe->format = PIX_FMT_RGB24;
+        s->scaleframe->format = AV_PIX_FMT_RGB24;
 
-        s->buffer = (uint8_t *)av_malloc(sizeof(uint8_t)*avpicture_get_size(PIX_FMT_RGB24, s->scaleframe->width, s->scaleframe->height));
-        avpicture_fill((AVPicture *)s->scaleframe, s->buffer, PIX_FMT_RGB24, s->video->frame->width, s->video->frame->height);
+        s->buffer = (uint8_t *)av_malloc(sizeof(uint8_t)*avpicture_get_size(s->scaleframe->format, s->scaleframe->width, s->scaleframe->height));
+        #if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(57,24,0)
+            av_image_fill_arrays(s->scaleframe->data, s->scaleframe->linesize, s->buffer, s->scaleframe->format, s->video->frame->width, s->video->frame->height, 1);
+        #else
+            avpicture_fill((AVPicture *)s->scaleframe, s->buffer, s->scaleframe->format, s->video->frame->width, s->video->frame->height);
+        #endif
 
         s->sws_context = sws_getCachedContext(NULL, s->video->frame->width, s->video->frame->height, s->video->frame->format,
-                s->scaleframe->width, s->scaleframe->height, PIX_FMT_RGB24, SWS_AREA, NULL, NULL, NULL);
+                s->scaleframe->width, s->scaleframe->height, s->scaleframe->format, SWS_AREA, NULL, NULL, NULL);
     }
 
     s->keyframes = NULL;
