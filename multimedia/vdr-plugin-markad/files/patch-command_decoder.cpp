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
 
@@ -113,6 +119,7 @@ cMarkAdDecoder::cMarkAdDecoder(bool useH
 
     noticeERRVID=false;
 
+#ifndef __FreeBSD__
     cpu_set_t cpumask;
     uint len = sizeof(cpumask);
     int cpucount=1;
@@ -120,6 +127,12 @@ cMarkAdDecoder::cMarkAdDecoder(bool useH
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
@@ -151,28 +164,28 @@ cMarkAdDecoder::cMarkAdDecoder(bool useH
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
+        video_codecid=AV_CODEC_ID_MPEG2VIDEO_XVMC;
     }
 
     video_codec = avcodec_find_decoder(video_codecid);
-    if ((!video_codec) && (video_codecid==CODEC_ID_MPEG2VIDEO_XVMC))
+    if ((!video_codec) && (video_codecid==AV_CODEC_ID_MPEG2VIDEO_XVMC))
     {
         // fallback to MPEG2VIDEO
-        video_codecid=CODEC_ID_MPEG2VIDEO;
+        video_codecid=AV_CODEC_ID_MPEG2VIDEO;
         video_codec=avcodec_find_decoder(video_codecid);
     }
 
     if (video_codec)
     {
-        video_context = avcodec_alloc_context();
+        video_context = avcodec_alloc_context3(NULL);
         if (video_context)
         {
             if (video_codec->capabilities & CODEC_CAP_TRUNCATED)
@@ -183,7 +196,7 @@ cMarkAdDecoder::cMarkAdDecoder(bool useH
 
             av_log_set_level(AV_LOG_FATAL); // silence decoder output
 
-            if (video_codecid==CODEC_ID_H264)
+            if (video_codecid==AV_CODEC_ID_H264)
             {
                 video_context->flags2|=CODEC_FLAG2_CHUNKS; // needed for H264!
             }
@@ -198,15 +211,15 @@ cMarkAdDecoder::cMarkAdDecoder(bool useH
 #else
             int ret=avcodec_open(video_context, video_codec);
 #endif
-            if ((ret < 0) && (video_codecid==CODEC_ID_MPEG2VIDEO_XVMC))
+            if ((ret < 0) && (video_codecid==AV_CODEC_ID_MPEG2VIDEO_XVMC))
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
                     memset(video_context->codec_name,0,sizeof(video_context->codec_name));
 #if LIBAVCODEC_VERSION_INT >= ((53<<16)+(5<<8)+0)
@@ -225,13 +238,13 @@ cMarkAdDecoder::cMarkAdDecoder(bool useH
             {
                 switch (video_codecid)
                 {
-                case CODEC_ID_H264:
+                case AV_CODEC_ID_H264:
                     esyslog("could not open codec for H264");
                     break;
-                case CODEC_ID_MPEG2VIDEO_XVMC:
+                case AV_CODEC_ID_MPEG2VIDEO_XVMC:
                     esyslog("could not open codec MPEG2 (XVMC)");
                     break;
-                case CODEC_ID_MPEG2VIDEO:
+                case AV_CODEC_ID_MPEG2VIDEO:
                     esyslog("could not open codec MPEG2");
                     break;
                 default:
@@ -256,7 +269,7 @@ cMarkAdDecoder::cMarkAdDecoder(bool useH
                 }
 #endif
 
-                video_frame = avcodec_alloc_frame();
+                video_frame = av_frame_alloc();
                 if (!video_frame)
                 {
                     esyslog("could not allocate frame");
@@ -286,13 +299,13 @@ cMarkAdDecoder::cMarkAdDecoder(bool useH
     {
         switch (video_codecid)
         {
-        case CODEC_ID_H264:
+        case AV_CODEC_ID_H264:
             esyslog("codec for H264 not found");
             break;
-        case CODEC_ID_MPEG2VIDEO_XVMC:
+        case AV_CODEC_ID_MPEG2VIDEO_XVMC:
             esyslog("codec for MPEG2 (XVMC) not found");
             break;
-        case CODEC_ID_MPEG2VIDEO:
+        case AV_CODEC_ID_MPEG2VIDEO:
             esyslog("codec for MPEG2 not found");
             break;
         default:
@@ -321,7 +334,7 @@ bool cMarkAdDecoder::Clear()
     {
         avcodec_flush_buffers(video_context);
         AVCodecContext *dest;
-        dest=avcodec_alloc_context();
+        dest=avcodec_alloc_context3(NULL);
         if (dest)
         {
             if (avcodec_copy_context(dest,video_context)!=0) ret=false;
@@ -384,7 +397,7 @@ bool cMarkAdDecoder::DecodeVideo(MarkAdC
     if (!video_frame) return false;
     maContext->Video.Data.Valid=false;
 
-    if ((video_context->codec_id==CODEC_ID_H264) && (!video_context->skip_frame))
+    if ((video_context->codec_id==AV_CODEC_ID_H264) && (!video_context->skip_frame))
     {
         // with H264 we cannot set skip_frame just to NONKEY, is depends on Interlaced...
         if (maContext->Video.Info.Height)
