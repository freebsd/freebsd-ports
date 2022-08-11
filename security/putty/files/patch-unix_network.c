--- unix/network.c.orig	2022-05-24 16:56:28 UTC
+++ unix/network.c
@@ -11,8 +11,13 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h>
 #include <arpa/inet.h>
+#else
+#include <arpa/inet.h>
 #include <netinet/in.h>
+#endif
 #include <netinet/tcp.h>
 #include <netdb.h>
 #include <sys/un.h>
