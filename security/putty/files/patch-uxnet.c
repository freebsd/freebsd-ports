--- uxnet.c.orig	Tue Feb  3 15:47:43 2004
+++ uxnet.c	Fri Feb 13 14:19:00 2004
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
 
