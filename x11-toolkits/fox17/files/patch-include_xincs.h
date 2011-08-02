--- include/xincs.h.orig	2011-08-02 10:41:42.000000000 +0200
+++ include/xincs.h	2011-08-02 10:42:11.000000000 +0200
@@ -110,7 +110,12 @@
 #include <grp.h>
 #include <pwd.h>
 #include <sys/ioctl.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/mount.h>
+#else
 #include <sys/statfs.h>
+#endif
 #ifdef HAVE_UNISTD_H
 #include <sys/types.h>
 #include <unistd.h>
