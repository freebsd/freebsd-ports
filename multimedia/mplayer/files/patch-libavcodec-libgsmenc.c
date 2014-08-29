--- ffmpeg/libavcodec/libgsmenc.c.orig	2014-08-15 11:02:02.619426519 +0200
+++ ffmpeg/libavcodec/libgsmenc.c	2014-08-15 11:02:28.587424476 +0200
@@ -28,11 +28,7 @@
 // The idiosyncrasies of GSM-in-WAV are explained at http://kbs.cs.tu-berlin.de/~jutta/toast.html
 
 #include "config.h"
-#if HAVE_GSM_H
 #include <gsm.h>
-#else
-#include <gsm/gsm.h>
-#endif
 
 #include "libavutil/common.h"
 
