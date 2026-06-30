--- src/file_analysis/analyzer/x509/X509.h.orig	2026-05-12 18:14:44 UTC
+++ src/file_analysis/analyzer/x509/X509.h
@@ -9,13 +9,15 @@
 #include "zeek/OpaqueVal.h"
 #include "zeek/file_analysis/analyzer/x509/X509Common.h"
 
-#if ( OPENSSL_VERSION_NUMBER < 0x10002000L ) || defined(LIBRESSL_VERSION_NUMBER)
+#if ( OPENSSL_VERSION_NUMBER < 0x10002000L ) ||                                                                        \
+    (defined(LIBRESSL_VERSION_NUMBER) && (LIBRESSL_VERSION_NUMBER < 0x30900000L))
 
 #define X509_get_signature_nid(x) OBJ_obj2nid((x)->sig_alg->algorithm)
 
 #endif
 
-#if ( OPENSSL_VERSION_NUMBER < 0x1010000fL ) || defined(LIBRESSL_VERSION_NUMBER)
+#if ( OPENSSL_VERSION_NUMBER < 0x1010000fL ) ||                                                                        \
+    (defined(LIBRESSL_VERSION_NUMBER) && (LIBRESSL_VERSION_NUMBER < 0x30900000L))
 
 #define X509_OBJECT_new() (X509_OBJECT*)malloc(sizeof(X509_OBJECT))
 #define X509_OBJECT_free(a) free(a)
