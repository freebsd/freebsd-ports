--- gst/librfb/gstrfbsrc.c.orig	Fri Jun  3 06:06:43 2005
+++ gst/librfb/gstrfbsrc.c	Fri Jun  3 06:08:21 2005
@@ -28,6 +28,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <unistd.h>
+#include <sys/time.h>
 
 #include <librfb/rfb.h>
 
