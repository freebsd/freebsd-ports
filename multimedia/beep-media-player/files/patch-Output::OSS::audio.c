--- Output/OSS/audio.c.orig	Tue Aug 24 22:26:01 2004
+++ Output/OSS/audio.c	Tue Aug 24 22:26:17 2004
@@ -26,6 +26,7 @@
 #include <fcntl.h>
 #include <errno.h>
 #include <sys/ioctl.h>
+#include <sys/time.h>
 
 #include "OSS.h"
 
