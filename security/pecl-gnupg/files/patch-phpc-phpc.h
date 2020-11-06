--- phpc/phpc.h.orig	2016-08-29 19:02:44 UTC
+++ phpc/phpc.h
@@ -29,6 +29,13 @@
 #error "Only PHP 5.2+ supported"
 #endif
 
+#if PHP_MAJOR_VERSION >= 8
+#define TSRMLS_C
+#define TSRMLS_CC
+#define TSRMLS_DC
+#define TSRMLS_FETCH()
+#endif
+
 /* no operation */
 #define PHPC_NOOP ((void) 0)
 
