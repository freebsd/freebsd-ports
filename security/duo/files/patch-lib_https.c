--- lib/https.c.orig	2025-07-08 19:38:07 UTC
+++ lib/https.c
@@ -9,6 +9,10 @@
 
 #include "config.h"
 
+#if defined(__FreeBSD__)
+#include <netinet/in.h>
+#endif
+
 #include <arpa/inet.h>
 #include <sys/types.h>
 #include <sys/socket.h>
