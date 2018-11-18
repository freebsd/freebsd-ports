--- winpr/libwinpr/sspi/NTLM/ntlm_compute.c.orig	2014-09-11 22:46:32 UTC
+++ winpr/libwinpr/sspi/NTLM/ntlm_compute.c
@@ -673,11 +673,24 @@ void ntlm_init_rc4_seal_states(NTLM_CONTEXT* context)
 
 void ntlm_compute_message_integrity_check(NTLM_CONTEXT* context)
 {
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	HMAC_CTX *hmac_ctx;
+#else
 	HMAC_CTX hmac_ctx;
+#endif
 	/*
 	 * Compute the HMAC-MD5 hash of ConcatenationOf(NEGOTIATE_MESSAGE,
 	 * CHALLENGE_MESSAGE, AUTHENTICATE_MESSAGE) using the ExportedSessionKey
 	 */
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	hmac_ctx = HMAC_CTX_new();
+	HMAC_Init_ex(hmac_ctx, context->ExportedSessionKey, 16, EVP_md5(), NULL);
+	HMAC_Update(hmac_ctx, (BYTE*) context->NegotiateMessage.pvBuffer, context->NegotiateMessage.cbBuffer);
+	HMAC_Update(hmac_ctx, (BYTE*) context->ChallengeMessage.pvBuffer, context->ChallengeMessage.cbBuffer);
+	HMAC_Update(hmac_ctx, (BYTE*) context->AuthenticateMessage.pvBuffer, context->AuthenticateMessage.cbBuffer);
+	HMAC_Final(hmac_ctx, context->MessageIntegrityCheck, NULL);
+	HMAC_CTX_free(hmac_ctx);
+#else
 	HMAC_CTX_init(&hmac_ctx);
 	HMAC_Init_ex(&hmac_ctx, context->ExportedSessionKey, 16, EVP_md5(), NULL);
 	HMAC_Update(&hmac_ctx, (BYTE*) context->NegotiateMessage.pvBuffer, context->NegotiateMessage.cbBuffer);
@@ -685,5 +698,6 @@ void ntlm_compute_message_integrity_check(NTLM_CONTEXT
 	HMAC_Update(&hmac_ctx, (BYTE*) context->AuthenticateMessage.pvBuffer, context->AuthenticateMessage.cbBuffer);
 	HMAC_Final(&hmac_ctx, context->MessageIntegrityCheck, NULL);
 	HMAC_CTX_cleanup(&hmac_ctx);
+#endif
 }
 
