--- ffmpeg/libavcodec/libgsm.c.orig	2011-03-12 15:13:38.000000000 +0100
+++ ffmpeg/libavcodec/libgsm.c	2011-03-18 17:17:26.901267039 +0100
@@ -28,7 +28,7 @@
 // The idiosyncrasies of GSM-in-WAV are explained at http://kbs.cs.tu-berlin.de/~jutta/toast.html
 
 #include "avcodec.h"
-#include <gsm/gsm.h>
+#include <gsm.h>
 
 // gsm.h misses some essential constants
 #define GSM_BLOCK_SIZE 33
