--- modules/codec/ffmpeg/postprocess.c.orig	Fri May 13 07:48:21 2005
+++ modules/codec/ffmpeg/postprocess.c	Sat May 14 00:11:53 2005
@@ -35,13 +35,9 @@
 
 #include "ffmpeg.h"
 
-#ifdef LIBAVCODEC_PP
+#if defined(LIBAVCODEC_PP) && LIBAVCODEC_BUILD > 4750
 
-#ifdef HAVE_POSTPROC_POSTPROCESS_H
-#   include <postproc/postprocess.h>
-#else
-#   include <libpostproc/postprocess.h>
-#endif
+#include <ffmpeg/postproc/postprocess.h>
 
 #ifndef PP_CPU_CAPS_ALTIVEC
 #   define PP_CPU_CAPS_ALTIVEC 0
