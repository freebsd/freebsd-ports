
$FreeBSD$

--- l2tpd.c.orig	Fri Jan 11 17:54:44 2002
+++ l2tpd.c	Tue Oct 22 12:43:45 2002
@@ -33,8 +33,6 @@
 #include <netdb.h>
 #include <string.h>
 #include <fcntl.h>
-#include <netinet/in.h>
-#include <arpa/inet.h>
 #ifdef USE_KERNEL
 #include <sys/ioctl.h>
 #endif
