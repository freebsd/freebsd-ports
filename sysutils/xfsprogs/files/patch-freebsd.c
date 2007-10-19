--- libxfs/freebsd.c.orig	2007-10-18 22:02:28.000000000 -0400
+++ libxfs/freebsd.c	2007-10-18 22:02:39.000000000 -0400
@@ -21,6 +21,7 @@
 #include <sys/disk.h>
 #include <sys/mount.h>
 #include <sys/ioctl.h>
+#include <sys/sysctl.h>
 
 int platform_has_uuid = 1;
 extern char *progname;
