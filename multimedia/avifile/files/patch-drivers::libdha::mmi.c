--- drivers/libdha/mmi.c.orig	Wed Oct  2 16:00:07 2002
+++ drivers/libdha/mmi.c	Wed Oct  2 16:00:14 2002
@@ -1,6 +1,7 @@
 /* Memory manager interface */
 #include <stdio.h>
 #include <sys/ioctl.h>
+#include <sys/types.h>
 #include <sys/mman.h> /* mlock */
 #include <errno.h>
 #include <unistd.h>
