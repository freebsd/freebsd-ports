--- modules/codec/ffmpeg/ffmpeg.h.orig	Fri Aug  8 19:08:32 2003
+++ modules/codec/ffmpeg/ffmpeg.h	Wed Nov  5 15:10:17 2003
@@ -49,11 +49,7 @@
 
 } generic_thread_t;
 
-#if LIBAVCODEC_BUILD >= 4663
-#   define LIBAVCODEC_PP
-#else
 #   undef  LIBAVCODEC_PP
-#endif
 
 #define GetWLE( p ) \
     ( *(u8*)(p) + ( *((u8*)(p)+1) << 8 ) )
