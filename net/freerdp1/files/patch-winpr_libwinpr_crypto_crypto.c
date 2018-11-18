--- winpr/libwinpr/crypto/crypto.c.orig	2018-11-06 02:41:23 UTC
+++ winpr/libwinpr/crypto/crypto.c
@@ -177,20 +177,37 @@ BOOL CryptProtectMemory(LPVOID pData, DWORD cbData, DW
 
 	SecureZeroMemory(randomKey, sizeof(randomKey));
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	pMemBlock->enc = EVP_CIPHER_CTX_new();
+	pMemBlock->dec = EVP_CIPHER_CTX_new();
+
+	EVP_CIPHER_CTX_init(pMemBlock->enc);
+	EVP_EncryptInit_ex(pMemBlock->enc, EVP_aes_256_cbc(), NULL, pMemBlock->key, pMemBlock->iv);
+
+	EVP_CIPHER_CTX_init(pMemBlock->dec);
+	EVP_DecryptInit_ex(pMemBlock->dec, EVP_aes_256_cbc(), NULL, pMemBlock->key, pMemBlock->iv);
+#else
 	EVP_CIPHER_CTX_init(&(pMemBlock->enc));
 	EVP_EncryptInit_ex(&(pMemBlock->enc), EVP_aes_256_cbc(), NULL, pMemBlock->key, pMemBlock->iv);
 
 	EVP_CIPHER_CTX_init(&(pMemBlock->dec));
 	EVP_DecryptInit_ex(&(pMemBlock->dec), EVP_aes_256_cbc(), NULL, pMemBlock->key, pMemBlock->iv);
+#endif
 
 	/* AES Encryption */
 
 	cbOut = pMemBlock->cbData + AES_BLOCK_SIZE - 1;
 	pCipherText = (BYTE*) malloc(cbOut);
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	EVP_EncryptInit_ex(pMemBlock->enc, NULL, NULL, NULL, NULL);
+	EVP_EncryptUpdate(pMemBlock->enc, pCipherText, &cbOut, pMemBlock->pData, pMemBlock->cbData);
+	EVP_EncryptFinal_ex(pMemBlock->enc, pCipherText + cbOut, &cbFinal);
+#else
 	EVP_EncryptInit_ex(&(pMemBlock->enc), NULL, NULL, NULL, NULL);
 	EVP_EncryptUpdate(&(pMemBlock->enc), pCipherText, &cbOut, pMemBlock->pData, pMemBlock->cbData);
 	EVP_EncryptFinal_ex(&(pMemBlock->enc), pCipherText + cbOut, &cbFinal);
+#endif
 
 	CopyMemory(pMemBlock->pData, pCipherText, pMemBlock->cbData);
 	free(pCipherText);
@@ -233,9 +250,15 @@ BOOL CryptUnprotectMemory(LPVOID pData, DWORD cbData, 
 	ListDictionary_Remove(g_ProtectedMemoryBlocks, pData);
 
 	/* AES Cleanup */
-
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	EVP_CIPHER_CTX_cleanup(pMemBlock->enc);
+	EVP_CIPHER_CTX_cleanup(pMemBlock->dec);
+	EVP_CIPHER_CTX_free(pMemBlock->enc);
+	EVP_CIPHER_CTX_free(pMemBlock->dec);
+#else
 	EVP_CIPHER_CTX_cleanup(&(pMemBlock->enc));
 	EVP_CIPHER_CTX_cleanup(&(pMemBlock->dec));
+#endif
 
 	free(pMemBlock);
 
