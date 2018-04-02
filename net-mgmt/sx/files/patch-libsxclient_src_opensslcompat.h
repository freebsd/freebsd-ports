--- libsxclient/src/opensslcompat.h.orig	2016-11-16 13:50:12 UTC
+++ libsxclient/src/opensslcompat.h
@@ -13,7 +13,7 @@
 #define hmac_final(a, b, c) (HMAC_Final((a), (b), (c)), 1)
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L|| defined (LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L|| (defined (LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 /* https://wiki.openssl.org/index.php/1.1_API_Changes#Adding_forward-compatible_code_to_older_versions */
 static HMAC_CTX *HMAC_CTX_new(void)
 {
@@ -32,13 +32,13 @@ static void HMAC_CTX_free(HMAC_CTX *ctx)
 }
 #endif
 
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined (LIBRESSL_VERSION_NUMBER)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || (defined (LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 /* EVP_MD_CTX_create() and EVP_MD_CTX_destroy() were renamed to EVP_MD_CTX_new() and EVP_MD_CTX_free() in OpenSSL 1.1. */
 #define EVP_MD_CTX_new EVP_MD_CTX_create
 #define EVP_MD_CTX_free EVP_MD_CTX_destroy
 #endif
 
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || (defined (LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 #define ASN1_STRING_get0_data(x) ASN1_STRING_data(x)
 #endif
 
