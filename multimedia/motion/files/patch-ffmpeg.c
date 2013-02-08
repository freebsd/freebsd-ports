--- ffmpeg.c.orig	2010-06-01 15:48:23.000000000 +0900
+++ ffmpeg.c	2012-06-08 23:21:55.000000000 +0900
@@ -36,6 +36,11 @@
 #    endif /* __GNUC__ */
 #endif /* LIBAVCODEC_BUILD > 4680 */
 
+#if defined LIBAVFORMAT_VERSION_MAJOR && defined LIBAVFORMAT_VERSION_MINOR 
+#if LIBAVFORMAT_VERSION_MAJOR < 53 && LIBAVFORMAT_VERSION_MINOR < 45
+    #define GUESS_NO_DEPRECATED 
+#endif
+#endif
 
 #if LIBAVFORMAT_BUILD >= 4616
 /* The API for av_write_frame changed with FFmpeg version 0.4.9pre1.
@@ -227,11 +232,13 @@
     mpeg1_file_protocol.url_seek  = file_protocol.url_seek;
     mpeg1_file_protocol.url_close = file_protocol.url_close;
 
-    /* Register the append file protocol. */
-#if LIBAVFORMAT_BUILD >= (52<<16 | 31<<8)
+/* Register the append file protocol. */
+#ifdef have_av_register_protocol2
+    av_register_protocol2(&mpeg1_file_protocol, sizeof(mpeg1_file_protocol));
+#elif defined have_av_register_protocol        
     av_register_protocol(&mpeg1_file_protocol);
 #else
-    register_protocol(&mpeg1_file_protocol);
+#   warning av_register_protocolXXX missing
 #endif
 }
 
@@ -258,7 +265,11 @@
         /* We use "mpeg1video" for raw mpeg1 format. Using "mpeg" would
          * result in a muxed output file, which isn't appropriate here.
          */
-        of = guess_format("mpeg1video", NULL, NULL);
+#ifdef GUESS_NO_DEPRECATED
+        of = guess_format("mpeg1video", NULL, NULL);        
+#else
+        of = av_guess_format("mpeg1video", NULL, NULL);
+#endif 
         if (of) {
             /* But we want the trailer to be correctly written. */
             of->write_trailer = mpeg1_write_trailer;
@@ -270,24 +281,44 @@
 #endif
     } else if (strcmp(codec, "mpeg4") == 0) {
         ext = ".avi";
-        of = guess_format("avi", NULL, NULL);
+#ifdef GUESS_NO_DEPRECATED
+        of = guess_format("mpeg1video", NULL, NULL);
+#else        
+        of = av_guess_format("avi", NULL, NULL);
+#endif        
     } else if (strcmp(codec, "msmpeg4") == 0) {
         ext = ".avi";
-        of = guess_format("avi", NULL, NULL);
+#ifdef GUESS_NO_DEPRECATED
+        of = guess_format("mpeg1video", NULL, NULL);
+#else        
+        of = av_guess_format("avi", NULL, NULL);
+#endif
         if (of) {
             /* Manually override the codec id. */
             of->video_codec = CODEC_ID_MSMPEG4V2;
         }
     } else if (strcmp(codec, "swf") == 0) {
         ext = ".swf";
-        of = guess_format("swf", NULL, NULL);
+#ifdef GUESS_NO_DEPRECATED
+        of = guess_format("mpeg1video", NULL, NULL);
+#else        
+        of = av_guess_format("swf", NULL, NULL);
+#endif        
     } else if (strcmp(codec, "flv") == 0) {
         ext = ".flv";
-        of = guess_format("flv", NULL, NULL);
+#ifdef GUESS_NO_DEPRECATED
+        of = guess_format("mpeg1video", NULL, NULL);
+#else        
+        of = av_guess_format("flv", NULL, NULL);
+#endif        
         of->video_codec = CODEC_ID_FLV1;
     } else if (strcmp(codec, "ffv1") == 0) {
         ext = ".avi";
-        of = guess_format("avi", NULL, NULL);
+#ifdef GUESS_NO_DEPRECATED
+        of = guess_format("mpeg1video", NULL, NULL);
+#else
+        of = av_guess_format("avi", NULL, NULL);
+#endif
         if (of) {
             /* Use the FFMPEG Lossless Video codec (experimental!).
                Requires strict_std_compliance to be <= -2 */
@@ -295,7 +326,11 @@
         }
     } else if (strcmp(codec, "mov") == 0) {
         ext = ".mov";
-        of = guess_format("mov", NULL, NULL);        
+#ifdef GUESS_NO_DEPRECATED
+        of = guess_format("mpeg1video", NULL, NULL);
+#else        
+        of = av_guess_format("mov", NULL, NULL);
+#endif
     } else {
         motion_log(LOG_ERR, 0, "ffmpeg_video_codec option value %s is not supported", codec);
         return NULL;
@@ -340,7 +375,13 @@
     snprintf(ffmpeg->codec, sizeof(ffmpeg->codec), "%s", ffmpeg_video_codec);
 
     /* allocation the output media context */
+#ifdef have_avformat_alloc_context
+    ffmpeg->oc = avformat_alloc_context();
+#elif defined have_av_avformat_alloc_context
+    ffmpeg->oc = av_alloc_format_context();
+#else
     ffmpeg->oc = av_mallocz(sizeof(AVFormatContext));
+#endif
 
     if (!ffmpeg->oc) {
         motion_log(LOG_ERR, 1, "Memory error while allocating output media context");
@@ -377,7 +418,11 @@
 
     ffmpeg->c     = c = AVSTREAM_CODEC_PTR(ffmpeg->video_st);
     c->codec_id   = ffmpeg->oc->oformat->video_codec;
+#if LIBAVCODEC_VERSION_MAJOR < 53    
     c->codec_type = CODEC_TYPE_VIDEO;
+#else
+    c->codec_type = AVMEDIA_TYPE_VIDEO;
+#endif    
     is_mpeg1      = c->codec_id == CODEC_ID_MPEG1VIDEO;
 
     if (strcmp(ffmpeg_video_codec, "ffv1") == 0)
@@ -646,7 +691,11 @@
     if (ffmpeg->oc->oformat->flags & AVFMT_RAWPICTURE) {
         /* raw video case. The API will change slightly in the near future for that */
 #ifdef FFMPEG_AVWRITEFRAME_NEWAPI
+#if LIBAVCODEC_VERSION_MAJOR < 53        
         pkt.flags |= PKT_FLAG_KEY;
+#else
+        pkt.flags |= AV_PKT_FLAG_KEY;  
+#endif        
         pkt.data = (uint8_t *)pic;
         pkt.size = sizeof(AVPicture);
         ret = av_write_frame(ffmpeg->oc, &pkt);
@@ -667,7 +716,11 @@
 #ifdef FFMPEG_AVWRITEFRAME_NEWAPI
             pkt.pts = AVSTREAM_CODEC_PTR(ffmpeg->video_st)->coded_frame->pts;
             if (AVSTREAM_CODEC_PTR(ffmpeg->video_st)->coded_frame->key_frame) {
+#if LIBAVCODEC_VERSION_MAJOR < 53                
                 pkt.flags |= PKT_FLAG_KEY;
+#else
+                pkt.flags |= AV_PKT_FLAG_KEY;
+#endif                
             }
             pkt.data = ffmpeg->video_outbuf;
             pkt.size = out_size;
