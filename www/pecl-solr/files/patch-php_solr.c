--- php_solr.c.orig	2014-06-22 19:01:39.785187204 +0800
+++ php_solr.c	2014-06-22 19:02:20.171185939 +0800
@@ -901,8 +901,6 @@
 
 /* {{{ solr_module_deps  */
 static zend_module_dep solr_module_deps[] = {
-    ZEND_MOD_REQUIRED(PHP_LIBXML_EXTENSION_NAME)
-    ZEND_MOD_REQUIRED(PHP_JSON_EXTENSION_NAME)
     { NULL, NULL, NULL }
 };
 /* }}} */
