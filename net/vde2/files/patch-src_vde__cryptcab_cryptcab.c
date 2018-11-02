--- src/vde_cryptcab/cryptcab.c.orig	2011-11-23 16:41:17 UTC
+++ src/vde_cryptcab/cryptcab.c
@@ -22,7 +22,11 @@ static void Usage(char *programname)
 	exit(1);
 }
 	
+#if OPENSSL_VERSION_NUMBER >= 0x1010100fL
+static EVP_CIPHER_CTX *ctx;
+#else
 static EVP_CIPHER_CTX ctx;
+#endif
 static int ctx_initialized = 0;
 static int encryption_disabled = 0;
 static int nfd;
@@ -103,19 +107,33 @@ int data_encrypt(unsigned char *src, unsigned char *ds
 	}
 
 	if (!ctx_initialized) {
+#if OPENSSL_VERSION_NUMBER >= 0x1010100fL
+		ctx = EVP_CIPHER_CTX_new();
+		EVP_CIPHER_CTX_init (ctx);
+#else
 		EVP_CIPHER_CTX_init (&ctx);
+#endif
 		ctx_initialized = 1;
 	}
 	
+#if OPENSSL_VERSION_NUMBER >= 0x1010100fL
+	EVP_EncryptInit (ctx, EVP_bf_cbc (), p->key, p->iv);
+	if (EVP_EncryptUpdate (ctx, dst, &olen, src, len) != 1)
+#else
 	EVP_EncryptInit (&ctx, EVP_bf_cbc (), p->key, p->iv);
 	if (EVP_EncryptUpdate (&ctx, dst, &olen, src, len) != 1)
+#endif
 	{
 		fprintf (stderr,"error in encrypt update\n");
 		olen = -1;
 		goto cleanup;
 	}
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010100fL
+	if (EVP_EncryptFinal (ctx, dst + olen, &tlen) != 1)
+#else
 	if (EVP_EncryptFinal (&ctx, dst + olen, &tlen) != 1)
+#endif
 	{
 		fprintf (stderr,"error in encrypt final\n");
 		olen = -1;
@@ -124,7 +142,12 @@ int data_encrypt(unsigned char *src, unsigned char *ds
 	olen += tlen;
 
 cleanup:
-	EVP_CIPHER_CTX_cleanup(&ctx);	
+#if OPENSSL_VERSION_NUMBER >= 0x1010100fL
+	EVP_CIPHER_CTX_cleanup(ctx);	
+	EVP_CIPHER_CTX_free(ctx);
+#else
+	EVP_CIPHER_CTX_cleanup(&ctx);
+#endif
 	return olen;
 }
 
@@ -138,19 +161,33 @@ int data_decrypt(unsigned char *src, unsigned char *ds
 	}
 	
 	if (!ctx_initialized) {
+#if OPENSSL_VERSION_NUMBER >= 0x1010100fL
+		ctx = EVP_CIPHER_CTX_new();
+		EVP_CIPHER_CTX_init(ctx);
+#else
 		EVP_CIPHER_CTX_init (&ctx);
+#endif
 		ctx_initialized = 1;
 	}
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010100fL
+	EVP_DecryptInit (ctx, EVP_bf_cbc (), p->key, p->iv);
+	if (EVP_DecryptUpdate (ctx, dst, &olen, src, len) != 1)
+#else
 	EVP_DecryptInit (&ctx, EVP_bf_cbc (), p->key, p->iv);
 	if (EVP_DecryptUpdate (&ctx, dst, &olen, src, len) != 1)
+#endif
 	{
 		fprintf (stderr,"error in decrypt update\n");
 		olen = -1;
 		goto cleanup;
 	}
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010100fL
+	if (EVP_DecryptFinal (ctx, dst + olen, &tlen) != 1)
+#else
 	if (EVP_DecryptFinal (&ctx, dst + olen, &tlen) != 1)
+#endif
 	{
 		fprintf (stderr,"error in decrypt final\n");
 		olen = -1;
@@ -159,7 +196,12 @@ int data_decrypt(unsigned char *src, unsigned char *ds
 	olen += tlen;
 
 cleanup:
-	EVP_CIPHER_CTX_cleanup(&ctx);	
+#if OPENSSL_VERSION_NUMBER >= 0x1010100fL
+	EVP_CIPHER_CTX_cleanup(ctx);	
+	EVP_CIPHER_CTX_free(ctx);
+#else
+	EVP_CIPHER_CTX_cleanup(&ctx);
+#endif
 	return olen;
 }
 
