--- sapi/apache2filter/php_functions.c.orig	Sat May 11 11:49:54 2002
+++ sapi/apache2filter/php_functions.c	Fri Jun 21 23:45:16 2002
@@ -90,7 +90,7 @@
 		ADD_STRING(method);
 		ADD_LONG(mtime);
 		ADD_LONG(clength);
-#if !MODULE_MAGIC_AT_LEAST(20020506,0)
+#if !AP_MODULE_MAGIC_AT_LEAST(20020506,0)
 		ADD_STRING(boundary);
 #endif
 		ADD_STRING(range);
