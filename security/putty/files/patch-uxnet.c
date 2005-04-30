--- uxnet.c.orig	Fri Apr 29 12:48:56 2005
+++ uxnet.c	Fri Apr 29 12:49:29 2005
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
