--- src/crypto/crypto_openssl.c.orig	2016-10-02 18:51:11 UTC
+++ src/crypto/crypto_openssl.c
@@ -33,7 +33,8 @@
 #include "aes_wrap.h"
 #include "crypto.h"
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
+	(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 /* Compatibility wrappers for older versions. */
 
 static HMAC_CTX * HMAC_CTX_new(void)
@@ -79,7 +80,8 @@ static void EVP_MD_CTX_free(EVP_MD_CTX *
 
 static BIGNUM * get_group5_prime(void)
 {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && \
+	!(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 	return BN_get_rfc3526_prime_1536(NULL);
 #elif !defined(OPENSSL_IS_BORINGSSL)
 	return get_rfc3526_prime_1536(NULL);
@@ -611,7 +613,8 @@ void crypto_cipher_deinit(struct crypto_
 
 void * dh5_init(struct wpabuf **priv, struct wpabuf **publ)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
+	(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 	DH *dh;
 	struct wpabuf *pubkey = NULL, *privkey = NULL;
 	size_t publen, privlen;
@@ -712,7 +715,8 @@ err:
 
 void * dh5_init_fixed(const struct wpabuf *priv, const struct wpabuf *publ)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
+	(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 	DH *dh;
 
 	dh = DH_new();
