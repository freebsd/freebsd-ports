--- modules/access/pvr.c.orig	2010-03-23 17:37:48.000000000 +0100
+++ modules/access/pvr.c	2010-03-23 17:38:04.000000000 +0100
@@ -38,7 +38,9 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <errno.h>
+#ifdef __linux__
 #include <linux/types.h>
+#endif
 #include <sys/ioctl.h>
 #include <sys/poll.h>
 #ifdef HAVE_NEW_LINUX_VIDEODEV2_H
