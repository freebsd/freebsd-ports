--- src/sfutil/util_net.c.orig	Fri Dec 19 14:18:45 2003
+++ src/sfutil/util_net.c	Fri Dec 19 14:19:04 2003
@@ -6,6 +6,7 @@
 
 #ifndef WIN32
 /* for inet_ntoa */
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
