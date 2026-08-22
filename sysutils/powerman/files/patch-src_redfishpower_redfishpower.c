--- src/redfishpower/redfishpower.c.orig	2024-09-11 17:18:33 UTC
+++ src/redfishpower/redfishpower.c
@@ -26,6 +26,9 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netdb.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
 #include <arpa/inet.h>
 #include <errno.h>
 #include <assert.h>
