--- mplayerxp/libdha/mmi.c.orig	Sun Nov 24 11:02:13 2002
+++ mplayerxp/libdha/mmi.c	Sun Nov 24 11:02:31 2002
@@ -1,6 +1,7 @@
 /* Memory manager interface */
 #include <stdio.h>
 #include <sys/ioctl.h>
+#include <sys/types.h>
 #include <sys/mman.h> /* mlock */
 #include <errno.h>
 #include <unistd.h>
