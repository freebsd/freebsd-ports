--- src/rmd_capture_sound.c.orig	2009-03-09 14:59:13.000000000 +0800
+++ src/rmd_capture_sound.c	2009-03-09 15:02:42.000000000 +0800
@@ -34,6 +34,10 @@
 #include <pthread.h>
 #include <string.h>
 #include <errno.h>
+#include <sys/types.h>
+#include <sys/uio.h>
+#include <unistd.h>
+#include <stdlib.h>
 
 
 void *CaptureSound(ProgData *pdata){
