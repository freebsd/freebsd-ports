--- src/ssl.c.orig	2016-01-18 12:03:01 UTC
+++ src/ssl.c
@@ -11,6 +11,7 @@
 const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);
 #else
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <resolv.h>
 #include <netdb.h>
 #include <arpa/inet.h>
