--- src/php_http_url.c.orig	2016-04-05 17:53:32 UTC
+++ src/php_http_url.c
@@ -27,6 +27,10 @@
 #	include <arpa/inet.h>
 #endif
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <stddef.h>
+#endif
+
 #include "php_http_utf8.h"
 
 static inline char *localhostname(void)
