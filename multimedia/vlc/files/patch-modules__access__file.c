--- modules/access/file.c.orig	2009-09-13 21:50:02.000000000 +0900
+++ modules/access/file.c	2009-09-13 21:50:37.000000000 +0900
@@ -52,6 +52,7 @@
 #   include <linux/magic.h>
 #   define HAVE_FSTATFS 1
 #elif defined (HAVE_SYS_MOUNT_H)
+#   include <sys/param.h>
 #   include <sys/mount.h>
 #   define HAVE_FSTATFS 1
 #endif
