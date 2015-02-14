--- php_http_url.c.orig	2015-02-08 20:13:52.746791000 +0800
+++ php_http_url.c	2015-02-08 20:14:36.050339000 +0800
@@ -25,6 +25,8 @@
 #	include <arpa/inet.h>
 #endif
 
+#include <stddef.h>
+
 #include "php_http_utf8.h"
 
 static inline char *localhostname(void)
