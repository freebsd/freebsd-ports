--- src/php_solr.h.orig	2025-11-11 22:20:54.799208000 +0800
+++ src/php_solr.h	2025-11-11 22:21:15.328071000 +0800
@@ -126,7 +126,7 @@
 #define solr_ce_Serializable zend_ce_serializable
 #define solr_ce_ArrayAccess  zend_ce_arrayaccess
 #define solr_ce_Iterator     zend_ce_iterator
-#define solr_ce_Exception    zend_exception_get_default()
+#define solr_ce_Exception    zend_ce_exception
 /* }}} */
 
 extern zend_object_handlers solr_object_handlers;
