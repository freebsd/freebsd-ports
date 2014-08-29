--- ffmpeg/libavcodec/libgsmdec.c.orig	2014-07-21 19:20:03.000000000 +0200
+++ ffmpeg/libavcodec/libgsmdec.c	2014-08-15 11:02:55.987422815 +0200
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
