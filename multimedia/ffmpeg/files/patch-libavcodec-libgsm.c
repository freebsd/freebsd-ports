--- libavcodec/libgsm.c.orig	2010-07-21 10:24:16.297810379 +0200
+++ libavcodec/libgsm.c	2010-07-21 10:24:22.915234561 +0200
@@ -28,7 +28,7 @@
 // The idiosyncrasies of GSM-in-WAV are explained at http://kbs.cs.tu-berlin.de/~jutta/toast.html
 
 #include "avcodec.h"
-#include <gsm/gsm.h>
+#include <gsm.h>
 
 // gsm.h misses some essential constants
 #define GSM_BLOCK_SIZE 33
