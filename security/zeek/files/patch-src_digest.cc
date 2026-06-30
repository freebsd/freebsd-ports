--- src/digest.cc.orig	2026-05-12 18:14:44 UTC
+++ src/digest.cc
@@ -12,7 +12,8 @@
 
 #include "zeek/Reporter.h"
 
-#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) || defined(LIBRESSL_VERSION_NUMBER)
+#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) ||                                                                        \
+    (defined(LIBRESSL_VERSION_NUMBER) && (LIBRESSL_VERSION_NUMBER < 0x30900000L))
 #define EVP_MD_CTX_new EVP_MD_CTX_create
 #define EVP_MD_CTX_free EVP_MD_CTX_destroy
 #endif
