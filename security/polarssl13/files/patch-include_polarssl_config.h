--- include/polarssl/config.h.bak	2014-04-11 22:33:59.000000000 +0900
+++ include/polarssl/config.h	2014-04-30 17:36:41.000000000 +0900
@@ -2383,4 +2383,6 @@
 #error "POLARSSL_X509_CSR_WRITE_C defined, but not all prerequisites"
 #endif
 
+#define SHOW_PROTOTYPE_CHANGE_WARNINGS
+
 #endif /* config.h */
