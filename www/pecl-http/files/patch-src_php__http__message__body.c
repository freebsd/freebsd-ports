--- src/php_http_message_body.c.orig	2024-08-03 15:37:59 UTC
+++ src/php_http_message_body.c
@@ -12,7 +12,11 @@
 
 #include "php_http_api.h"
 
+#if PHP_VERSION_ID <= 80300
 #include "ext/standard/php_lcg.h"
+#else
+#include "ext/random/php_random.h"
+#endif
 
 #define BOUNDARY_OPEN(body) \
 	do {\
