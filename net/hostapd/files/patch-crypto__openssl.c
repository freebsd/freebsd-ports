--- src/crypto/crypto_openssl.c.orig	2017-04-21 20:53:34 UTC
+++ src/crypto/crypto_openssl.c
@@ -611,7 +611,7 @@ void crypto_cipher_deinit(struct crypto_
 
 void * dh5_init(struct wpabuf **priv, struct wpabuf **publ)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined (LIBRESSL_VERSION_NUMBER)
 	DH *dh;
 	struct wpabuf *pubkey = NULL, *privkey = NULL;
 	size_t publen, privlen;
@@ -712,7 +712,7 @@ err:
 
 void * dh5_init_fixed(const struct wpabuf *priv, const struct wpabuf *publ)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 	DH *dh;
 
 	dh = DH_new();
