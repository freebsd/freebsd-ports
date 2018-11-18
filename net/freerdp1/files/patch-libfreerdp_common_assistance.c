--- libfreerdp/common/assistance.c.orig	2018-11-06 05:10:45 UTC
+++ libfreerdp/common/assistance.c
@@ -478,7 +478,11 @@ BYTE* freerdp_assistance_encrypt_pass_stub(const char*
 	int cbPassStubW;
 	int EncryptedSize;
 	BYTE PasswordHash[16];
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	EVP_CIPHER_CTX *rc4Ctx;
+#else
 	EVP_CIPHER_CTX rc4Ctx;
+#endif
 	BYTE *pbIn, *pbOut;
 	int cbOut, cbIn, cbFinal;
 	WCHAR* PasswordW = NULL;
@@ -516,9 +520,16 @@ BYTE* freerdp_assistance_encrypt_pass_stub(const char*
 	*((UINT32*) pbIn) = cbPassStubW;
 	CopyMemory(&pbIn[4], PassStubW, cbPassStubW);
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	rc4Ctx = EVP_CIPHER_CTX_new();
+	EVP_CIPHER_CTX_init(rc4Ctx);
+
+	status = EVP_EncryptInit_ex(rc4Ctx, EVP_rc4(), NULL, NULL, NULL);
+#else
 	EVP_CIPHER_CTX_init(&rc4Ctx);
 
 	status = EVP_EncryptInit_ex(&rc4Ctx, EVP_rc4(), NULL, NULL, NULL);
+#endif
 
 	if (!status)
 	{
@@ -526,7 +537,11 @@ BYTE* freerdp_assistance_encrypt_pass_stub(const char*
 		return NULL;
 	}
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	status = EVP_EncryptInit_ex(rc4Ctx, NULL, NULL, PasswordHash, NULL);
+#else
 	status = EVP_EncryptInit_ex(&rc4Ctx, NULL, NULL, PasswordHash, NULL);
+#endif
 
 	if (!status)
 	{
@@ -537,7 +552,11 @@ BYTE* freerdp_assistance_encrypt_pass_stub(const char*
 	cbOut = cbFinal = 0;
 	cbIn = EncryptedSize;
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	status = EVP_EncryptUpdate(rc4Ctx, pbOut, &cbOut, pbIn, cbIn);
+#else
 	status = EVP_EncryptUpdate(&rc4Ctx, pbOut, &cbOut, pbIn, cbIn);
+#endif
 
 	if (!status)
 	{
@@ -545,7 +564,11 @@ BYTE* freerdp_assistance_encrypt_pass_stub(const char*
 		return NULL;
 	}
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	status = EVP_EncryptFinal_ex(rc4Ctx, pbOut + cbOut, &cbFinal);
+#else
 	status = EVP_EncryptFinal_ex(&rc4Ctx, pbOut + cbOut, &cbFinal);
+#endif
 
 	if (!status)
 	{
@@ -553,7 +576,11 @@ BYTE* freerdp_assistance_encrypt_pass_stub(const char*
 		return NULL;
 	}
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	EVP_CIPHER_CTX_free(rc4Ctx);
+#else
 	EVP_CIPHER_CTX_cleanup(&rc4Ctx);
+#endif
 
 	free(pbIn);
 	free(PasswordW);
@@ -571,7 +598,11 @@ int freerdp_assistance_decrypt2(rdpAssistanceFile* fil
 	int cbPasswordW;
 	int cchOutW = 0;
 	WCHAR* pbOutW = NULL;
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	EVP_CIPHER_CTX *aesDec;
+#else
 	EVP_CIPHER_CTX aesDec;
+#endif
 	WCHAR* PasswordW = NULL;
 	BYTE *pbIn, *pbOut;
 	int cbOut, cbIn, cbFinal;
@@ -598,17 +629,31 @@ int freerdp_assistance_decrypt2(rdpAssistanceFile* fil
 
 	ZeroMemory(InitializationVector, sizeof(InitializationVector));
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	aesDec = EVP_CIPHER_CTX_new();
+	EVP_CIPHER_CTX_init(aesDec);
+
+	status = EVP_DecryptInit_ex(aesDec, EVP_aes_128_cbc(), NULL, NULL, NULL);
+#else
 	EVP_CIPHER_CTX_init(&aesDec);
 
 	status = EVP_DecryptInit_ex(&aesDec, EVP_aes_128_cbc(), NULL, NULL, NULL);
+#endif
 
 	if (status != 1)
 		return -1;
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	EVP_CIPHER_CTX_set_key_length(aesDec, (128 / 8));
+	EVP_CIPHER_CTX_set_padding(aesDec, 0);
+
+	status = EVP_DecryptInit_ex(aesDec, EVP_aes_128_cbc(), NULL, DerivedKey, InitializationVector);
+#else
 	EVP_CIPHER_CTX_set_key_length(&aesDec, (128 / 8));
 	EVP_CIPHER_CTX_set_padding(&aesDec, 0);
 
 	status = EVP_DecryptInit_ex(&aesDec, EVP_aes_128_cbc(), NULL, DerivedKey, InitializationVector);
+#endif
 
 	if (status != 1)
 		return -1;
@@ -621,12 +666,20 @@ int freerdp_assistance_decrypt2(rdpAssistanceFile* fil
 	if (!pbOut)
 		return -1;
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	status = EVP_DecryptUpdate(aesDec, pbOut, &cbOut, pbIn, cbIn);
+#else
 	status = EVP_DecryptUpdate(&aesDec, pbOut, &cbOut, pbIn, cbIn);
+#endif
 
 	if (status != 1)
 		return -1;
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	status = EVP_DecryptFinal_ex(aesDec, pbOut + cbOut, &cbFinal);
+#else
 	status = EVP_DecryptFinal_ex(&aesDec, pbOut + cbOut, &cbFinal);
+#endif
 
 	if (status != 1)
 	{
@@ -634,7 +687,11 @@ int freerdp_assistance_decrypt2(rdpAssistanceFile* fil
 		return -1;
 	}
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	EVP_CIPHER_CTX_free(aesDec);
+#else
 	EVP_CIPHER_CTX_cleanup(&aesDec);
+#endif
 
 	cbOut += cbFinal;
 	cbFinal = 0;
