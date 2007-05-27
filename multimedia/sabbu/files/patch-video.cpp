Index: Source/video.cpp
===================================================================
RCS file: /cvsroot/sabbu/sabbu/Source/video.cpp,v
retrieving revision 1.36
diff -u -r1.36 video.cpp
--- Source/video.cpp	11 Aug 2005 17:16:17 -0000	1.36
+++ Source/video.cpp	24 Nov 2005 09:40:33 -0000
@@ -213,7 +213,7 @@
 
   for(i = 0; i < video->ic->nb_streams; i++) 
   {
-    AVCodecContext *enc = &video->ic->streams[i]->codec;
+    AVCodecContext *enc = video->ic->streams[i]->codec;
     if(enc->codec_type == CODEC_TYPE_VIDEO)
     {
       video->video_index = i;
@@ -227,7 +227,7 @@
     throw kryError(_("The video file does not seem to contain a video stream."));
   }
 
-  enc = &video->ic->streams[video->video_index]->codec;
+  enc = video->ic->streams[video->video_index]->codec;
   enc->debug_mv = 0;
   enc->debug = 0;
   enc->workaround_bugs = 1;
@@ -291,9 +291,9 @@
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
@@ -302,14 +302,14 @@
       return FALSE;
   }
 
-  width = video->ic->streams[video->video_index]->codec.width;
-  height = video->ic->streams[video->video_index]->codec.height;
+  width = video->ic->streams[video->video_index]->codec->width;
+  height = video->ic->streams[video->video_index]->codec->height;
 
   pict->data[0] = (uint8_t*) malloc(4 * width * height);
   pict->linesize[0] = width * 4;
 
   if(img_convert(pict, dst_pix_fmt, 
-    (AVPicture *) frame, video->ic->streams[video->video_index]->codec.pix_fmt, 
+    (AVPicture *) frame, video->ic->streams[video->video_index]->codec->pix_fmt, 
     width, height) < 0)
   {
     av_free(frame);
@@ -323,17 +323,17 @@
 
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
@@ -348,7 +348,7 @@
     free(video->last_pkt);
     video->last_pkt = NULL;
   }
-  avcodec_close(&video->ic->streams[video->video_index]->codec);
+  avcodec_close(video->ic->streams[video->video_index]->codec);
   av_close_input_file(video->ic);
 }
 
@@ -376,11 +376,11 @@
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
