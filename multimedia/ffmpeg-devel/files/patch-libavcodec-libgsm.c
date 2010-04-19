--- libavcodec/libgsm.c.orig	2010-04-18 19:05:53.640509610 +0200
+++ libavcodec/libgsm.c	2010-04-18 19:05:59.140526816 +0200
@@ -28,7 +28,7 @@
 // The idiosyncrasies of GSM-in-WAV are explained at http://kbs.cs.tu-berlin.de/~jutta/toast.html
 
 #include "avcodec.h"
-#include <gsm/gsm.h>
+#include <gsm.h>
 
 // gsm.h misses some essential constants
 #define GSM_BLOCK_SIZE 33
