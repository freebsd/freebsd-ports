--- libavcodec/libgsm.c.orig	2012-01-22 14:41:15.000000000 +0100
+++ libavcodec/libgsm.c	2012-01-22 16:06:24.357156664 +0100
@@ -27,7 +27,7 @@
 
 // The idiosyncrasies of GSM-in-WAV are explained at http://kbs.cs.tu-berlin.de/~jutta/toast.html
 
-#include <gsm/gsm.h>
+#include <gsm.h>
 
 #include "avcodec.h"
 #include "gsm.h"
