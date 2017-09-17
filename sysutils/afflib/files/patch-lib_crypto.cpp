--- lib/crypto.cpp.orig	2016-09-12 18:18:01 UTC
+++ lib/crypto.cpp
@@ -26,7 +26,7 @@ using namespace std;
 #endif
 
 /* Support OpenSSL before 1.1.0 */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #define EVP_MD_CTX_new EVP_MD_CTX_create
 #define EVP_MD_CTX_free EVP_MD_CTX_destroy
 #endif
