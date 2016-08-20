--- src/php7/php_solr.c.orig	2016-03-30 13:42:31 UTC
+++ src/php7/php_solr.c
@@ -1029,8 +1029,6 @@ static zend_function_entry solr_utils_me
 
 /* {{{ solr_module_deps  */
 static zend_module_dep solr_module_deps[] = {
-    ZEND_MOD_REQUIRED(PHP_LIBXML_EXTENSION_NAME)
-    ZEND_MOD_REQUIRED(PHP_JSON_EXTENSION_NAME)
     ZEND_MOD_END
 };
 /* }}} */
