--- ffmpeg/libavcodec/libgsm.c.orig	2012-01-29 19:20:05.000000000 +0100
+++ ffmpeg/libavcodec/libgsm.c	2012-03-22 18:07:58.682722034 +0100
@@ -27,7 +27,7 @@
 
 // The idiosyncrasies of GSM-in-WAV are explained at http://kbs.cs.tu-berlin.de/~jutta/toast.html
 
-#include <gsm/gsm.h>
+#include <gsm.h>
 
 #include "avcodec.h"
 #include "gsm.h"
