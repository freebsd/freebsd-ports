--- nse_openssl.cc.orig	2022-09-01 22:22:29 UTC
+++ nse_openssl.cc
@@ -13,7 +13,9 @@
 #include <openssl/hmac.h>
 #include <openssl/rand.h>
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && !defined LIBRESSL_VERSION_NUMBER
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && \
+    ((!defined LIBRESSL_VERSION_NUMBER) || \
+    (defined LIBRESSL_VERSION_NUMBER && LIBRESSL_VERSION_NUMBER >= 0x30500000L))
 #define HAVE_OPAQUE_STRUCTS 1
 #define FUNC_EVP_MD_CTX_init EVP_MD_CTX_reset
 #define FUNC_EVP_MD_CTX_cleanup EVP_MD_CTX_reset
