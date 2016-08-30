--- src/php5/php_solr.c.orig	2016-03-30 13:42:30 UTC
+++ src/php5/php_solr.c
@@ -1030,8 +1030,6 @@ static zend_function_entry solr_utils_me
 
 /* {{{ solr_module_deps  */
 static zend_module_dep solr_module_deps[] = {
-    ZEND_MOD_REQUIRED(PHP_LIBXML_EXTENSION_NAME)
-    ZEND_MOD_REQUIRED(PHP_JSON_EXTENSION_NAME)
     ZEND_MOD_END
 };
 /* }}} */
