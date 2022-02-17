--- php_proctitle.h.orig	2012-05-11 08:49:30 UTC
+++ php_proctitle.h
@@ -21,6 +21,15 @@
 #ifndef PHP_PROCTITLE_H
 #define PHP_PROCTITLE_H
 
+
+#if PHP_MAJOR_VERSION >= 8
+#define TSRMLS_CC
+#define TSRMLS_C
+#define TSRMLS_DC
+#define TSRMLS_D
+#define TSRMLS_FETCH()
+#endif
+
 #define PHP_PROCTITLE_VERSION "0.1.2"
 
 extern zend_module_entry proctitle_module_entry;
