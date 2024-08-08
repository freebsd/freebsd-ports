--- src/php_http_misc.c.orig	2024-08-03 15:35:31 UTC
+++ src/php_http_misc.c
@@ -12,7 +12,11 @@
 
 #include "php_http_api.h"
 
+#if PHP_VERSION_ID <= 80300
 #include "ext/standard/php_lcg.h"
+#else
+#include "ext/random/php_random.h"
+#endif
 #include "zend_exceptions.h"
 
 /* SLEEP */
