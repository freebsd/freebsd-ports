--- ps/global.c.orig	2016-07-09 21:49:25 UTC
+++ ps/global.c
@@ -28,7 +28,9 @@
 
 #include <sys/ioctl.h>
 #include <sys/stat.h>
+#ifndef __FreeBSD__
 #include <sys/sysmacros.h>
+#endif
 #include <sys/types.h>
 
 #include "../proc/wchan.h"
