--- src/core.c.orig	2022-04-06 18:56:08 UTC
+++ src/core.c
@@ -11,6 +11,9 @@
 #include <hiredis/hiredis_ssl.h>
 #endif
 #include <arpa/inet.h>
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#endif
 
 #include "cache/cache.h"
 
