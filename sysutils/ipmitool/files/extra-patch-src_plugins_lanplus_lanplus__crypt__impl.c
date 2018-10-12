--- src/plugins/lanplus/lanplus_crypt_impl.c.orig	2016-05-28 08:20:20 UTC
+++ src/plugins/lanplus/lanplus_crypt_impl.c
@@ -164,11 +164,7 @@ lanplus_encrypt_aes_cbc_128(const uint8_t * iv,
 							uint8_t       * output,
 							uint32_t        * bytes_written)
 {
-	EVP_CIPHER_CTX ctx;
-	EVP_CIPHER_CTX_init(&ctx);
-	EVP_EncryptInit_ex(&ctx, EVP_aes_128_cbc(), NULL, key, iv);
-	EVP_CIPHER_CTX_set_padding(&ctx, 0);
-	
+	EVP_CIPHER_CTX *ctx = NULL;
 
 	*bytes_written = 0;
 
@@ -182,6 +178,13 @@ lanplus_encrypt_aes_cbc_128(const uint8_t * iv,
 		printbuf(input, input_length, "encrypting this data");
 	}
 
+	ctx = EVP_CIPHER_CTX_new();
+	if (ctx == NULL) {
+		lprintf(LOG_DEBUG, "ERROR: EVP_CIPHER_CTX_new() failed");
+		return;
+	}
+	EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv);
+	EVP_CIPHER_CTX_set_padding(ctx, 0);
 
 	/*
 	 * The default implementation adds a whole block of padding if the input
@@ -191,28 +194,28 @@ lanplus_encrypt_aes_cbc_128(const uint8_t * iv,
 	assert((input_length % IPMI_CRYPT_AES_CBC_128_BLOCK_SIZE) == 0);
 
 
-	if(!EVP_EncryptUpdate(&ctx, output, (int *)bytes_written, input, input_length))
+	if(!EVP_EncryptUpdate(ctx, output, (int *)bytes_written, input, input_length))
 	{
 		/* Error */
 		*bytes_written = 0;
-		return;
 	}
 	else
 	{
 		uint32_t tmplen;
 
-		if(!EVP_EncryptFinal_ex(&ctx, output + *bytes_written, (int *)&tmplen))
+		if(!EVP_EncryptFinal_ex(ctx, output + *bytes_written, (int *)&tmplen))
 		{
+			/* Error */
 			*bytes_written = 0;
-			return; /* Error */
 		}
 		else
 		{
 			/* Success */
 			*bytes_written += tmplen;
-			EVP_CIPHER_CTX_cleanup(&ctx);
 		}
 	}
+	/* performs cleanup and free */
+	EVP_CIPHER_CTX_free(ctx);
 }
 
 
@@ -239,12 +242,8 @@ lanplus_decrypt_aes_cbc_128(const uint8_t * iv,
 							uint8_t       * output,
 							uint32_t        * bytes_written)
 {
-	EVP_CIPHER_CTX ctx;
-	EVP_CIPHER_CTX_init(&ctx);
-	EVP_DecryptInit_ex(&ctx, EVP_aes_128_cbc(), NULL, key, iv);
-	EVP_CIPHER_CTX_set_padding(&ctx, 0);
+	EVP_CIPHER_CTX *ctx;
 
-
 	if (verbose >= 5)
 	{
 		printbuf(iv,  16, "decrypting with this IV");
@@ -252,12 +251,19 @@ lanplus_decrypt_aes_cbc_128(const uint8_t * iv,
 		printbuf(input, input_length, "decrypting this data");
 	}
 
-
 	*bytes_written = 0;
 
 	if (input_length == 0)
 		return;
 
+	ctx = EVP_CIPHER_CTX_new();
+	if (ctx == NULL) {
+		*bytes_written = 0;
+		return;
+	}
+	EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv);
+	EVP_CIPHER_CTX_set_padding(ctx, 0);
+
 	/*
 	 * The default implementation adds a whole block of padding if the input
 	 * data is perfectly aligned.  We would like to keep that from happening.
@@ -266,31 +272,29 @@ lanplus_decrypt_aes_cbc_128(const uint8_t * iv,
 	assert((input_length % IPMI_CRYPT_AES_CBC_128_BLOCK_SIZE) == 0);
 
 
-	if (!EVP_DecryptUpdate(&ctx, output, (int *)bytes_written, input, input_length))
+	if (!EVP_DecryptUpdate(ctx, output, (int *)bytes_written, input, input_length))
 	{
 		/* Error */
 		lprintf(LOG_DEBUG, "ERROR: decrypt update failed");
 		*bytes_written = 0;
-		return;
 	}
 	else
 	{
 		uint32_t tmplen;
 
-		if (!EVP_DecryptFinal_ex(&ctx, output + *bytes_written, (int *)&tmplen))
+		if (!EVP_DecryptFinal_ex(ctx, output + *bytes_written, (int *)&tmplen))
 		{
+			/* Error */
 			char buffer[1000];
 			ERR_error_string(ERR_get_error(), buffer);
 			lprintf(LOG_DEBUG, "the ERR error %s", buffer);
 			lprintf(LOG_DEBUG, "ERROR: decrypt final failed");
 			*bytes_written = 0;
-			return; /* Error */
 		}
 		else
 		{
 			/* Success */
 			*bytes_written += tmplen;
-			EVP_CIPHER_CTX_cleanup(&ctx);
 		}
 	}
 
@@ -299,4 +303,6 @@ lanplus_decrypt_aes_cbc_128(const uint8_t * iv,
 		lprintf(LOG_DEBUG, "Decrypted %d encrypted bytes", input_length);
 		printbuf(output, *bytes_written, "Decrypted this data");
 	}
+	/* performs cleanup and free */
+	EVP_CIPHER_CTX_free(ctx);
 }
