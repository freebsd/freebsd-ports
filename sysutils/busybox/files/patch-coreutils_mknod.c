--- coreutils/mknod.c.orig	2021-01-01 10:52:27 UTC
+++ coreutils/mknod.c
@@ -36,7 +36,9 @@
 //usage:       "$ mknod /dev/fd0 b 2 0\n"
 //usage:       "$ mknod -m 644 /tmp/pipe p\n"
 
+#ifdef __linux__
 #include <sys/sysmacros.h>  // For makedev
+#endif
 
 #include "libbb.h"
 #include "libcoreutils/coreutils.h"
