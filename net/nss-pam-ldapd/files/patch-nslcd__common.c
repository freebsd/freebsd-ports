--- ./nslcd/common.c.orig	2009-02-27 17:27:08.000000000 +0000
+++ ./nslcd/common.c	2009-08-02 22:32:27.000000000 +0000
@@ -27,6 +27,9 @@
 #include <stdarg.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
 #include <arpa/inet.h>
 #include <strings.h>
 #include <limits.h>
