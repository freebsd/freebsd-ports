--- ffmpeg/libavcodec/libgsm.c.orig	2013-03-07 19:20:04.000000000 +0100
+++ ffmpeg/libavcodec/libgsm.c	2013-03-22 16:31:14.983780842 +0100
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
