--- modules/codec/ffmpeg/ffmpeg.c.orig	Fri Aug  8 19:08:32 2003
+++ modules/codec/ffmpeg/ffmpeg.c	Wed Nov  5 15:07:26 2003
@@ -296,8 +296,7 @@
         avcodec_register_all();
         b_ffmpeginit = 1;
 
-        msg_Dbg( p_decoder->p_fifo, "libavcodec initialized (interface "
-                                    LIBAVCODEC_BUILD_STR ")" );
+        msg_Dbg( p_decoder->p_fifo, "libavcodec initialized" );
     }
     else
     {
