--- lib/libXDAAP/httpClient.c.orig
+++ lib/libXDAAP/httpClient.c
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
