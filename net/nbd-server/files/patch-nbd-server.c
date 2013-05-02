--- ./nbd-server.c.orig	2012-07-04 05:54:53.000000000 +0900
+++ ./nbd-server.c	2013-04-04 19:36:34.000000000 +0900
@@ -72,6 +72,7 @@
 #ifdef HAVE_SYS_MOUNT_H
 #include <sys/mount.h>
 #endif
+#include <sys/uio.h>
 #include <signal.h>
 #include <errno.h>
 #include <netinet/tcp.h>
