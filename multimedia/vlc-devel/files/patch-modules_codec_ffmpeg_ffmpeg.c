--- modules/codec/ffmpeg/ffmpeg.c.orig	Fri May 13 07:48:21 2005
+++ modules/codec/ffmpeg/ffmpeg.c	Fri May 13 13:28:17 2005
@@ -42,11 +42,9 @@
 
 #include "ffmpeg.h"
 
-#ifdef LIBAVCODEC_PP
+#if defined(LIBAVCODEC_PP) && LIBAVCODEC_BUILD > 4750
 #   ifdef HAVE_POSTPROC_POSTPROCESS_H
-#       include <postproc/postprocess.h>
-#   else
-#       include <libpostproc/postprocess.h>
+#       include <ffmpeg/postproc/postprocess.h>
 #   endif
 #endif
 
@@ -105,7 +103,7 @@
         VLC_TRUE );
         change_integer_range( 0, 2 );
 
-#ifdef LIBAVCODEC_PP
+#if defined(LIBAVCODEC_PP) && LIBAVCODEC_BUILD > 4750
     add_integer( "ffmpeg-pp-q", 0, NULL, PP_Q_TEXT, PP_Q_LONGTEXT, VLC_FALSE );
     add_string( "ffmpeg-pp-name", "default", NULL, LIBAVCODEC_PP_TEXT,
         LIBAVCODEC_PP_LONGTEXT, VLC_TRUE );
