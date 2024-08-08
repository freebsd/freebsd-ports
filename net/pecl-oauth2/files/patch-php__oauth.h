--- php_oauth.h.orig	2024-08-03 14:03:00 UTC
+++ php_oauth.h
@@ -29,7 +29,11 @@
 #include "php_main.h"
 #include "php_ini.h"
 #include "ext/standard/php_string.h"
+#if PHP_VERSION_ID <= 80300
 #include "ext/standard/php_rand.h"
+#else
+#include "ext/random/php_random.h"
+#endif
 #include "ext/standard/php_smart_string.h"
 #include "ext/standard/info.h"
 #include "ext/standard/php_string.h"
@@ -41,7 +45,6 @@
 #include "php_globals.h"
 #include "ext/standard/file.h"
 #include "ext/standard/base64.h"
-#include "ext/standard/php_lcg.h"
 #include "ext/pcre/php_pcre.h"
 #include "php_network.h"
 
