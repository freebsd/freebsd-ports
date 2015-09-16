--- ffmpeg/libavcodec/libgsmdec.c.orig	2015-06-19 20:44:39 UTC
+++ ffmpeg/libavcodec/libgsmdec.c
@@ -28,11 +28,7 @@
 // The idiosyncrasies of GSM-in-WAV are explained at http://kbs.cs.tu-berlin.de/~jutta/toast.html
 
 #include "config.h"
-#if HAVE_GSM_H
 #include <gsm.h>
-#else
-#include <gsm/gsm.h>
-#endif
 
 #include "libavutil/channel_layout.h"
 #include "libavutil/common.h"
