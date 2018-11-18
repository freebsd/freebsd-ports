--- winpr/libwinpr/sspi/NTLM/ntlm.c.orig	2014-09-11 22:46:32 UTC
+++ winpr/libwinpr/sspi/NTLM/ntlm.c
@@ -793,7 +793,11 @@ SECURITY_STATUS SEC_ENTRY ntlm_EncryptMessage(PCtxtHan
 	int length;
 	void* data;
 	UINT32 SeqNo;
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	HMAC_CTX *hmac;
+#else
 	HMAC_CTX hmac;
+#endif
 	BYTE digest[16];
 	BYTE checksum[8];
 	BYTE* signature;
@@ -827,12 +831,21 @@ SECURITY_STATUS SEC_ENTRY ntlm_EncryptMessage(PCtxtHan
 
 	CopyMemory(data, data_buffer->pvBuffer, length);
 	/* Compute the HMAC-MD5 hash of ConcatenationOf(seq_num,data) using the client signing key */
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	hmac = HMAC_CTX_new();
+	HMAC_Init_ex(hmac, context->SendSigningKey, 16, EVP_md5(), NULL);
+	HMAC_Update(hmac, (void*) &(SeqNo), 4);
+	HMAC_Update(hmac, (void*) data, length);
+	HMAC_Final(hmac, digest, NULL);
+	HMAC_CTX_free(hmac);
+#else
 	HMAC_CTX_init(&hmac);
 	HMAC_Init_ex(&hmac, context->SendSigningKey, 16, EVP_md5(), NULL);
 	HMAC_Update(&hmac, (void*) &(SeqNo), 4);
 	HMAC_Update(&hmac, (void*) data, length);
 	HMAC_Final(&hmac, digest, NULL);
 	HMAC_CTX_cleanup(&hmac);
+#endif
 
 	/* Encrypt message using with RC4, result overwrites original buffer */
 
@@ -869,7 +882,11 @@ SECURITY_STATUS SEC_ENTRY ntlm_DecryptMessage(PCtxtHan
 	int length;
 	void* data;
 	UINT32 SeqNo;
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	HMAC_CTX *hmac;
+#else
 	HMAC_CTX hmac;
+#endif
 	BYTE digest[16];
 	BYTE checksum[8];
 	UINT32 version = 1;
@@ -911,12 +928,21 @@ SECURITY_STATUS SEC_ENTRY ntlm_DecryptMessage(PCtxtHan
 		CopyMemory(data_buffer->pvBuffer, data, length);
 
 	/* Compute the HMAC-MD5 hash of ConcatenationOf(seq_num,data) using the client signing key */
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	hmac = HMAC_CTX_new();
+	HMAC_Init_ex(hmac, context->RecvSigningKey, 16, EVP_md5(), NULL);
+	HMAC_Update(hmac, (void*) &(SeqNo), 4);
+	HMAC_Update(hmac, (void*) data_buffer->pvBuffer, data_buffer->cbBuffer);
+	HMAC_Final(hmac, digest, NULL);
+	HMAC_CTX_free(hmac);
+#else
 	HMAC_CTX_init(&hmac);
 	HMAC_Init_ex(&hmac, context->RecvSigningKey, 16, EVP_md5(), NULL);
 	HMAC_Update(&hmac, (void*) &(SeqNo), 4);
 	HMAC_Update(&hmac, (void*) data_buffer->pvBuffer, data_buffer->cbBuffer);
 	HMAC_Final(&hmac, digest, NULL);
 	HMAC_CTX_cleanup(&hmac);
+#endif
 #ifdef WITH_DEBUG_NTLM
 	WLog_DBG(TAG, "Encrypted Data Buffer (length = %d)", length);
 	winpr_HexDump(TAG, WLOG_DEBUG, data, length);
