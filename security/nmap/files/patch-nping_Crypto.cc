--- nping/Crypto.cc.orig	2022-02-18 17:38:46 UTC
+++ nping/Crypto.cc
@@ -70,7 +70,9 @@
 #include <openssl/evp.h>
 #include <openssl/err.h>
 
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && !defined LIBRESSL_VERSION_NUMBER
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L) && \
+    ((!defined LIBRESSL_VERSION_NUMBER) || \
+    (defined LIBRESSL_VERSION_NUMBER && LIBRESSL_VERSION_NUMBER >= 0x30500000L))
 #define HAVE_OPAQUE_EVP_PKEY 1
 #define FUNC_EVP_MD_CTX_init EVP_MD_CTX_reset
 #define FUNC_EVP_MD_CTX_cleanup EVP_MD_CTX_reset
