--- Source/video.cpp.orig	2005-08-11 19:16:17.000000000 +0200
+++ Source/video.cpp	2010-01-24 10:30:13.000000000 +0100
@@ -74,9 +74,11 @@
 }
 #else
 
+extern "C" {
 #ifndef _WINDOWS
 #include <ffmpeg/avformat.h>
 #include <ffmpeg/avcodec.h>
+#include <libswscale/swscale.h>
 #else
 void (*av_register_all)(void) = NULL;
 int (*av_open_input_file)(AVFormatContext **ic_ptr, const char *filename, AVInputFormat *fmt, int buf_size, AVFormatParameters *ap) = NULL;
@@ -99,6 +101,7 @@
 int (*avpicture_alloc)(AVPicture *picture, int pix_fmt, int width, int height) = NULL;
 void (*avpicture_free)(AVPicture *picture) = NULL;
 #endif
+}
 
 
 GModule *module_avformat = NULL;
@@ -213,7 +216,7 @@
 
   for(i = 0; i < video->ic->nb_streams; i++) 
   {
-    AVCodecContext *enc = &video->ic->streams[i]->codec;
+    AVCodecContext *enc = video->ic->streams[i]->codec;
     if(enc->codec_type == CODEC_TYPE_VIDEO)
     {
       video->video_index = i;
@@ -227,7 +230,7 @@
     throw kryError(_("The video file does not seem to contain a video stream."));
   }
 
-  enc = &video->ic->streams[video->video_index]->codec;
+  enc = video->ic->streams[video->video_index]->codec;
   enc->debug_mv = 0;
   enc->debug = 0;
   enc->workaround_bugs = 1;
@@ -277,10 +280,16 @@
   avpicture_free(pict);
 }
 
+static struct SwsContext *img_convert_ctx;
+
 int video_get_picture(struct video_ffmpeg *video, AVPicture *pict)
 {
   AVFrame *frame;
+#if 0
   int dst_pix_fmt = PIX_FMT_RGBA32;
+#else
+  PixelFormat dst_pix_fmt = PIX_FMT_RGB32;
+#endif
   int got_picture;
   int len;
   int width, height;
@@ -291,9 +300,9 @@
   frame = avcodec_alloc_frame();
   while(1)
   {
-    len = avcodec_decode_video(&video->ic->streams[video->video_index]->codec, 
-                                frame, &got_picture, 
-                                video->last_pkt->data, video->last_pkt->size);
+    len = avcodec_decode_video(video->ic->streams[video->video_index]->codec, 
+                               frame, &got_picture, 
+                               video->last_pkt->data, video->last_pkt->size);
 
     if(got_picture)
       break;
@@ -302,15 +311,26 @@
       return FALSE;
   }
 
-  width = video->ic->streams[video->video_index]->codec.width;
-  height = video->ic->streams[video->video_index]->codec.height;
+  width = video->ic->streams[video->video_index]->codec->width;
+  height = video->ic->streams[video->video_index]->codec->height;
 
   pict->data[0] = (uint8_t*) malloc(4 * width * height);
   pict->linesize[0] = width * 4;
 
+#if 0
   if(img_convert(pict, dst_pix_fmt, 
-    (AVPicture *) frame, video->ic->streams[video->video_index]->codec.pix_fmt, 
+    (AVPicture *) frame, video->ic->streams[video->video_index]->codec->pix_fmt, 
     width, height) < 0)
+#else
+  img_convert_ctx = sws_getContext(width, height,
+                                   video->ic->streams[video->video_index]->codec->pix_fmt,
+                                   width, height,
+                                   dst_pix_fmt, SWS_BICUBIC,  NULL, NULL, NULL);
+  if (sws_scale(img_convert_ctx, frame->data,
+            frame->linesize, 0,
+            height,
+            pict->data, pict->linesize) < 0)
+#endif
   {
     av_free(frame);
     return FALSE;
@@ -323,17 +343,17 @@
 
 int video_get_width(struct video_ffmpeg *video)
 {
-  return video->ic->streams[video->video_index]->codec.width;
+  return video->ic->streams[video->video_index]->codec->width;
 }
 
 int video_get_height(struct video_ffmpeg *video)
 {
-  return video->ic->streams[video->video_index]->codec.height;
+  return video->ic->streams[video->video_index]->codec->height;
 }
 
 double video_get_fps(struct video_ffmpeg *video)
 {
-  return (video->ic->streams[video->video_index]->r_frame_rate / (double) video->ic->streams[video->video_index]->r_frame_rate_base);
+  return (video->ic->streams[video->video_index]->r_frame_rate.num / (double) video->ic->streams[video->video_index]->r_frame_rate.den);
 }
 
 int64_t video_get_duration(struct video_ffmpeg *video)
@@ -348,7 +368,7 @@
     free(video->last_pkt);
     video->last_pkt = NULL;
   }
-  avcodec_close(&video->ic->streams[video->video_index]->codec);
+  avcodec_close(video->ic->streams[video->video_index]->codec);
   av_close_input_file(video->ic);
 }
 
@@ -376,11 +396,11 @@
     if(av_seek_frame(video->ic, -1, target_time) < 0)
     #endif
     {
-      g_warning("seek failed... %lld", target_time);
+      g_warning("seek failed... %lld", (long long) target_time);
       return FALSE;
     }
 
-    avcodec_flush_buffers(&video->ic->streams[video->video_index]->codec);
+    avcodec_flush_buffers(video->ic->streams[video->video_index]->codec);
   }
 
   if(video->last_pkt)
