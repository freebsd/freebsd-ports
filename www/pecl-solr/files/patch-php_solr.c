--- php_solr.c.orig	2013-01-28 00:00:42.000000000 +0800
+++ php_solr.c	2013-01-28 00:00:54.000000000 +0800
@@ -879,8 +879,6 @@ static zend_function_entry solr_utils_me
 
 /* {{{ solr_module_deps  */
 static zend_module_dep solr_module_deps[] = {
-    ZEND_MOD_REQUIRED(PHP_CURL_EXTENSION_NAME)
-    ZEND_MOD_REQUIRED(PHP_LIBXML_EXTENSION_NAME)
 
     { NULL, NULL, NULL }
 };
