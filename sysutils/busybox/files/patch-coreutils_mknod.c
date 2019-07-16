--- coreutils/mknod.c.orig	2018-12-30 15:14:20 UTC
+++ coreutils/mknod.c
@@ -36,7 +36,8 @@
 //usage:       "$ mknod /dev/fd0 b 2 0\n"
 //usage:       "$ mknod -m 644 /tmp/pipe p\n"
 
-#include <sys/sysmacros.h>  // For makedev
+// #include <sys/sysmacros.h>  // For makedev
+#include <sys/types.h>
 
 #include "libbb.h"
 #include "libcoreutils/coreutils.h"
