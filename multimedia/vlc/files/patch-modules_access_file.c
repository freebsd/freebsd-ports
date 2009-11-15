--- ./modules/access/file.c.orig	2009-08-09 23:50:57.000000000 +0200
+++ ./modules/access/file.c	2009-11-14 18:12:22.000000000 +0100
@@ -50,7 +50,7 @@
 #if defined (__linux__)
 #   include <sys/vfs.h>
 #   include <linux/magic.h>
-#elif defined (HAVE_SYS_MOUNT_H)
+#elif defined (HAVE_SYS_MOUNT_H) || (defined(__FreeBSD__) && (_FreeBSD_version < 700000))
 #   include <sys/param.h>
 #   include <sys/mount.h>
 #endif
