--- unix/uxnet.c.orig	2019-03-16 12:26:37 UTC
+++ unix/uxnet.c
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
