--- php_pHash.h.orig	2013-04-23 18:53:42 UTC
+++ php_pHash.h
@@ -170,6 +170,14 @@ ZEND_END_ARG_INFO()
 #define ph_compare_text_hashes_arg_info NULL
 #endif
 
+#if PHP_VERSION_ID >= 70000
+#define SIZETorINT size_t
+#define zppLONG zend_long
+#else
+#define SIZETorINT int
+#define zppLONG long
+#endif
+
 #ifdef  __cplusplus
 } // extern "C" 
 #endif
