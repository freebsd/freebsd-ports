--- winpr/libwinpr/crypto/crypto.h.orig	2018-11-06 02:39:40 UTC
+++ winpr/libwinpr/crypto/crypto.h
@@ -41,8 +41,13 @@ struct _WINPR_PROTECTED_MEMORY_BLOCK
 	BYTE key[32];
 	BYTE iv[32];
 	BYTE salt[8];
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	EVP_CIPHER_CTX *enc;
+	EVP_CIPHER_CTX *dec;
+#else
 	EVP_CIPHER_CTX enc;
 	EVP_CIPHER_CTX dec;
+#endif
 };
 typedef struct _WINPR_PROTECTED_MEMORY_BLOCK WINPR_PROTECTED_MEMORY_BLOCK;
 
