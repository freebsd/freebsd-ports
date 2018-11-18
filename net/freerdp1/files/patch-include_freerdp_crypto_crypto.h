--- include/freerdp/crypto/crypto.h.orig	2018-11-06 02:55:10 UTC
+++ include/freerdp/crypto/crypto.h
@@ -61,12 +61,20 @@ struct crypto_rc4_struct
 
 struct crypto_des3_struct
 {
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	EVP_CIPHER_CTX *des3_ctx;
+#else
 	EVP_CIPHER_CTX des3_ctx;
+#endif
 };
 
 struct crypto_hmac_struct
 {
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	HMAC_CTX *hmac_ctx;
+#else
 	HMAC_CTX hmac_ctx;
+#endif
 };
 
 struct crypto_cert_struct
