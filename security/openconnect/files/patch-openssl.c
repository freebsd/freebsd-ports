--- openssl.c.orig	2016-07-09 14:43:41 UTC
+++ openssl.c
@@ -36,11 +36,11 @@
 #include <openssl/ui.h>
 #include <openssl/rsa.h>
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined (LIBRESSL_VERSION_NUMBER)
 #define X509_up_ref(x) 	CRYPTO_add(&(x)->references, 1, CRYPTO_LOCK_X509)
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined (LIBRESSL_VERSION_NUMBER)
 #define EVP_MD_CTX_new EVP_MD_CTX_create
 #define EVP_MD_CTX_free EVP_MD_CTX_destroy
 #define X509_STORE_CTX_get0_chain(ctx) ((ctx)->chain)
@@ -991,7 +991,7 @@ static int set_peer_cert_hash(struct ope
 	return 0;
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10002000L
+#if OPENSSL_VERSION_NUMBER < 0x10002000L || defined (LIBRESSL_VERSION_NUMBER)
 static int match_hostname_elem(const char *hostname, int helem_len,
 			       const char *match, int melem_len)
 {
