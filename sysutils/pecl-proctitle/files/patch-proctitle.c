--- proctitle.c.orig	2012-05-11 08:49:30 UTC
+++ proctitle.c
@@ -23,6 +23,7 @@
 #endif
 
 #include <php.h>
+#include "ext/standard/info.h"
 #include <SAPI.h>
 #include <dlfcn.h>
 #include <string.h>
@@ -138,9 +139,7 @@ PHP_MINFO_FUNCTION(proctitle)
 /* {{{ proctitle_module_entry
  */
 zend_module_entry proctitle_module_entry = {
-#if ZEND_MODULE_API_NO >= 20010901
 	STANDARD_MODULE_HEADER,
-#endif
 	"proctitle",
 	proctitle_functions,
 #ifndef PHP_SYSTEM_PROVIDES_SETPROCTITLE
@@ -152,9 +151,7 @@ zend_module_entry proctitle_module_entry = {
 	NULL,
 	NULL,
 	PHP_MINFO(proctitle),
-#if ZEND_MODULE_API_NO >= 20010901
 	PHP_PROCTITLE_VERSION,
-#endif
 	STANDARD_MODULE_PROPERTIES
 };
 /* }}} */
