--- ps/display.c.orig	2016-07-09 21:49:25 UTC
+++ ps/display.c
@@ -26,7 +26,10 @@
 #include <string.h>
 #include <unistd.h>
 
+
+#ifndef __FreeBSD__
 #include <sys/sysmacros.h>
+#endif
 #include <sys/types.h>
 
 #include "../proc/alloc.h"
