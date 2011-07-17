--- ./uxnet.c.orig	2009-08-07 00:55:15.000000000 +0200
+++ ./uxnet.c	2011-07-17 14:55:44.000000000 +0200
@@ -11,8 +11,13 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#include <arpa/inet.h>
+#else
 #include <arpa/inet.h>
 #include <netinet/in.h>
+#endif
 #include <netinet/tcp.h>
 #include <netdb.h>
 #include <sys/un.h>
