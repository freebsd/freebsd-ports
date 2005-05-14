--- modules/stream_out/switcher.c.orig	Wed Mar 23 03:57:15 2005
+++ modules/stream_out/switcher.c	Wed Mar 23 03:57:50 2005
@@ -44,7 +44,7 @@
 #ifdef HAVE_POSTPROC_POSTPROCESS_H
 #   include <postproc/postprocess.h>
 #else
-#   include <libpostproc/postprocess.h>
+#   include <ffmpeg/postproc/postprocess.h>
 #endif
 
 #define SOUT_CFG_PREFIX "sout-switcher-"
