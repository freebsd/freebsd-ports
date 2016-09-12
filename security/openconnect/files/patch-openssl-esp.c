--- openssl-esp.c.orig	2016-07-08 15:35:18 UTC
+++ openssl-esp.c
@@ -27,7 +27,7 @@
 #include <openssl/evp.h>
 #include <openssl/rand.h>
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
 #define EVP_CIPHER_CTX_free(c) do {				\
 				    EVP_CIPHER_CTX_cleanup(c);	\
@@ -85,7 +85,7 @@ static int init_esp_ciphers(struct openc
 	}
 	EVP_CIPHER_CTX_set_padding(esp->cipher, 0);
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined (LIBRESSL_VERSION_NUMBER)
 	esp->hmac = malloc(sizeof(*esp->hmac));
 	esp->pkt_hmac = malloc(sizeof(*esp->pkt_hmac));
 	if (!esp->hmac || &esp->pkt_hmac) {
