--- command/decoder.cpp.orig	2012-04-02 19:41:15 UTC
+++ command/decoder.cpp
@@ -6,11 +6,17 @@
  */
 
 #include <stdint.h>
+#ifndef __FreeBSD__
 #include <sched.h>
+#else
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 #include <errno.h>
 #include <sys/types.h>
 #include <string.h>
 #include <cstdlib>
+#include <stdio.h>
 
 #include "decoder.h"
 
@@ -113,6 +119,7 @@ cMarkAdDecoder::cMarkAdDecoder(bool useH264, int Threa
 
     noticeERRVID=false;
 
+#ifndef __FreeBSD__
     cpu_set_t cpumask;
     uint len = sizeof(cpumask);
     int cpucount=1;
@@ -120,6 +127,12 @@ cMarkAdDecoder::cMarkAdDecoder(bool useH264, int Threa
     {
         cpucount=CPU_COUNT(&cpumask);
     }
+#else
+    int cpucount;
+    size_t cpus_size = sizeof(cpucount);
+    if (sysctlbyname("hw.ncpu", &cpucount, &cpus_size, NULL, 0) == -1)
+        cpucount = 1;
+#endif
 
     if (Threads==-1)
     {
@@ -151,41 +164,47 @@ cMarkAdDecoder::cMarkAdDecoder(bool useH264, int Threa
     }
 
     video_codec=NULL;
-    CodecID video_codecid;
+    AVCodecID video_codecid;
 
     if (useH264)
     {
-        video_codecid=CODEC_ID_H264;
+        video_codecid=AV_CODEC_ID_H264;
     }
     else
     {
-        video_codecid=CODEC_ID_MPEG2VIDEO_XVMC;
+#ifdef AV_CODEC_ID_MPEG2VIDEO_XVMC
+        video_codecid=AV_CODEC_ID_MPEG2VIDEO_XVMC;
+#else
+        video_codecid=AV_CODEC_ID_MPEG2VIDEO;
+#endif
     }
 
     video_codec = avcodec_find_decoder(video_codecid);
-    if ((!video_codec) && (video_codecid==CODEC_ID_MPEG2VIDEO_XVMC))
+#ifdef AV_CODEC_ID_MPEG2VIDEO_XVMC
+    if ((!video_codec) && (video_codecid==AV_CODEC_ID_MPEG2VIDEO_XVMC))
     {
         // fallback to MPEG2VIDEO
-        video_codecid=CODEC_ID_MPEG2VIDEO;
+        video_codecid=AV_CODEC_ID_MPEG2VIDEO;
         video_codec=avcodec_find_decoder(video_codecid);
     }
+#endif
 
     if (video_codec)
     {
-        video_context = avcodec_alloc_context();
+        video_context = avcodec_alloc_context3(NULL);
         if (video_context)
         {
-            if (video_codec->capabilities & CODEC_CAP_TRUNCATED)
-                video_context->flags|=CODEC_FLAG_TRUNCATED; // we do not send complete frames
+            if (video_codec->capabilities & AV_CODEC_CAP_TRUNCATED)
+                video_context->flags|=AV_CODEC_FLAG_TRUNCATED; // we do not send complete frames
 
-            video_context->flags2|=CODEC_FLAG2_FAST; // really?
+            video_context->flags2|=AV_CODEC_FLAG2_FAST; // really?
             video_context->skip_idct=AVDISCARD_ALL;
 
             av_log_set_level(AV_LOG_FATAL); // silence decoder output
 
-            if (video_codecid==CODEC_ID_H264)
+            if (video_codecid==AV_CODEC_ID_H264)
             {
-                video_context->flags2|=CODEC_FLAG2_CHUNKS; // needed for H264!
+                video_context->flags2|=AV_CODEC_FLAG2_CHUNKS; // needed for H264!
             }
             else
             {
@@ -198,17 +217,23 @@ cMarkAdDecoder::cMarkAdDecoder(bool useH264, int Threa
 #else
             int ret=avcodec_open(video_context, video_codec);
 #endif
-            if ((ret < 0) && (video_codecid==CODEC_ID_MPEG2VIDEO_XVMC))
+#ifdef AV_CODEC_ID_MPEG2VIDEO_XVMC
+            if ((ret < 0) && (video_codecid==AV_CODEC_ID_MPEG2VIDEO_XVMC))
+#else
+            if (ret < 0)
+#endif
             {
                 // fallback to MPEG2VIDEO
-                video_codecid=CODEC_ID_MPEG2VIDEO;
+                video_codecid=AV_CODEC_ID_MPEG2VIDEO;
                 video_codec=avcodec_find_decoder(video_codecid);
                 if (video_codec)
                 {
                     video_context->codec_type=AVMEDIA_TYPE_UNKNOWN;
-                    video_context->codec_id=CODEC_ID_NONE;
+                    video_context->codec_id=AV_CODEC_ID_NONE;
                     video_context->codec_tag=0;
+#if LIBAVCODEC_VERSION_INT < ((58<<16)+(0<<8)+0)
                     memset(video_context->codec_name,0,sizeof(video_context->codec_name));
+#endif
 #if LIBAVCODEC_VERSION_INT >= ((53<<16)+(5<<8)+0)
                     video_context->thread_count=threadcount;
                     ret=avcodec_open2(video_context, video_codec, NULL);
@@ -225,13 +250,15 @@ cMarkAdDecoder::cMarkAdDecoder(bool useH264, int Threa
             {
                 switch (video_codecid)
                 {
-                case CODEC_ID_H264:
+                case AV_CODEC_ID_H264:
                     esyslog("could not open codec for H264");
                     break;
-                case CODEC_ID_MPEG2VIDEO_XVMC:
+#ifdef AV_CODEC_ID_MPEG2VIDEO_XVMC
+                case AV_CODEC_ID_MPEG2VIDEO_XVMC:
                     esyslog("could not open codec MPEG2 (XVMC)");
                     break;
-                case CODEC_ID_MPEG2VIDEO:
+#endif
+                case AV_CODEC_ID_MPEG2VIDEO:
                     esyslog("could not open codec MPEG2");
                     break;
                 default:
@@ -256,7 +283,7 @@ cMarkAdDecoder::cMarkAdDecoder(bool useH264, int Threa
                 }
 #endif
 
-                video_frame = avcodec_alloc_frame();
+                video_frame = av_frame_alloc();
                 if (!video_frame)
                 {
                     esyslog("could not allocate frame");
@@ -286,13 +313,15 @@ cMarkAdDecoder::cMarkAdDecoder(bool useH264, int Threa
     {
         switch (video_codecid)
         {
-        case CODEC_ID_H264:
+        case AV_CODEC_ID_H264:
             esyslog("codec for H264 not found");
             break;
-        case CODEC_ID_MPEG2VIDEO_XVMC:
+#ifdef AV_CODEC_ID_MPEG2VIDEO_XVMC
+        case AV_CODEC_ID_MPEG2VIDEO_XVMC:
             esyslog("codec for MPEG2 (XVMC) not found");
             break;
-        case CODEC_ID_MPEG2VIDEO:
+#endif
+        case AV_CODEC_ID_MPEG2VIDEO:
             esyslog("codec for MPEG2 not found");
             break;
         default:
@@ -321,7 +350,7 @@ bool cMarkAdDecoder::Clear()
     {
         avcodec_flush_buffers(video_context);
         AVCodecContext *dest;
-        dest=avcodec_alloc_context();
+        dest=avcodec_alloc_context3(NULL);
         if (dest)
         {
             if (avcodec_copy_context(dest,video_context)!=0) ret=false;
@@ -384,7 +413,7 @@ bool cMarkAdDecoder::DecodeVideo(MarkAdContext *maCont
     if (!video_frame) return false;
     maContext->Video.Data.Valid=false;
 
-    if ((video_context->codec_id==CODEC_ID_H264) && (!video_context->skip_frame))
+    if ((video_context->codec_id==AV_CODEC_ID_H264) && (!video_context->skip_frame))
     {
         // with H264 we cannot set skip_frame just to NONKEY, is depends on Interlaced...
         if (maContext->Video.Info.Height)
