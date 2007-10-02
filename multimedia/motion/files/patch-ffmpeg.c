--- ffmpeg.c.orig	2007-07-18 09:18:05.000000000 +0200
+++ ffmpeg.c	2007-10-03 01:05:23.000000000 +0200
@@ -126,6 +126,7 @@
 /* ffmpeg_init initializes for libavformat. */
 void ffmpeg_init()
 {
+	URLProtocol file_protocol;
 	av_register_all();
 	av_log_set_callback( (void *)ffmpeg_avcodec_log );
 
