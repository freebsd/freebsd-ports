--- ext/ming/php_ming.h.orig	Mon Apr  8 02:46:22 2002
+++ ext/ming/php_ming.h	Fri Jan  3 19:35:55 2003
@@ -24,7 +24,7 @@
 extern zend_module_entry ming_module_entry;
 #define ming_module_ptr &ming_module_entry
 
-#include <ming.h>
+#include <ming/ming.h>
 
 PHP_RINIT_FUNCTION(ming);
 PHP_MINIT_FUNCTION(ming);
