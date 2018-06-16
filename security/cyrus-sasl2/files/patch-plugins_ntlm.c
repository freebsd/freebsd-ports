--- plugins/ntlm.c.orig	2018-02-14 13:10:38 UTC
+++ plugins/ntlm.c
@@ -420,6 +420,29 @@ static unsigned char *P24(unsigned char 
     return P24;
 }
 
+static HMAC_CTX *_plug_HMAC_CTX_new(const sasl_utils_t *utils)
+{
+    utils->log(NULL, SASL_LOG_DEBUG, "_plug_HMAC_CTX_new()");
+
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    return HMAC_CTX_new();
+#else
+    return utils->malloc(sizeof(EVP_MD_CTX));
+#endif    
+}
+
+static void _plug_HMAC_CTX_free(HMAC_CTX *ctx, const sasl_utils_t *utils)
+{
+    utils->log(NULL, SASL_LOG_DEBUG, "_plug_HMAC_CTX_free()");
+
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    HMAC_CTX_free(ctx);
+#else
+    HMAC_cleanup(ctx);
+    utils->free(ctx);
+#endif    
+}
+
 static unsigned char *V2(unsigned char *V2, sasl_secret_t *passwd,
 			 const char *authid, const char *target,
 			 const unsigned char *challenge,
@@ -427,7 +450,7 @@ static unsigned char *V2(unsigned char *
 			 const sasl_utils_t *utils,
 			 char **buf, unsigned *buflen, int *result)
 {
-    HMAC_CTX ctx;
+    HMAC_CTX *ctx = NULL;
     unsigned char hash[EVP_MAX_MD_SIZE];
     char *upper;
     unsigned int len;
@@ -438,6 +461,10 @@ static unsigned char *V2(unsigned char *
 	SETERROR(utils, "cannot allocate NTLMv2 hash");
 	*result = SASL_NOMEM;
     }
+    else if ((ctx = _plug_HMAC_CTX_new(utils)) == NULL) {
+        SETERROR(utils, "cannot allocate HMAC CTX");
+        *result = SASL_NOMEM;
+    }
     else {
 	/* NTLMv2hash = HMAC-MD5(NTLMhash, unicode(ucase(authid + domain))) */
 	P16_nt(hash, passwd, utils, buf, buflen, result);
@@ -453,17 +480,18 @@ static unsigned char *V2(unsigned char *
 		(unsigned char *) *buf, 2 * len, hash, &len);
 
 	/* V2 = HMAC-MD5(NTLMv2hash, challenge + blob) + blob */
-	HMAC_Init(&ctx, hash, len, EVP_md5());
-	HMAC_Update(&ctx, challenge, NTLM_NONCE_LENGTH);
-	HMAC_Update(&ctx, blob, bloblen);
-	HMAC_Final(&ctx, V2, &len);
-	HMAC_cleanup(&ctx);
+	HMAC_Init_ex(ctx, hash, len, EVP_md5(), NULL);
+	HMAC_Update(ctx, challenge, NTLM_NONCE_LENGTH);
+	HMAC_Update(ctx, blob, bloblen);
+	HMAC_Final(ctx, V2, &len);
 
 	/* the blob is concatenated outside of this function */
 
 	*result = SASL_OK;
     }
 
+    if (ctx) _plug_HMAC_CTX_free(ctx, utils);
+
     return V2;
 }
 
