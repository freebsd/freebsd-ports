--- ./xbmc/lib/libXDAAP/httpClient.c.orig	2009-03-28 03:32:24.000000000 +0100
+++ ./xbmc/lib/libXDAAP/httpClient.c	2010-12-01 12:17:34.243841426 +0100
@@ -61,6 +61,11 @@
 #include <netinet/in.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/socket.h>
+#endif /* __FreeBSD__ */
+
 struct HTTP_ConnectionTAG
 {
     char *host;
