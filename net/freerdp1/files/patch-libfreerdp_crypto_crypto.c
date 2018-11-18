--- libfreerdp/crypto/crypto.c.orig	2018-11-06 02:56:44 UTC
+++ libfreerdp/crypto/crypto.c
@@ -92,9 +92,16 @@ CryptoDes3 crypto_des3_encrypt_init(const BYTE* key, c
 	if (!des3)
 		return NULL;
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	des3->des3_ctx = EVP_CIPHER_CTX_new();
+	EVP_CIPHER_CTX_init(des3->des3_ctx);
+	EVP_EncryptInit_ex(des3->des3_ctx, EVP_des_ede3_cbc(), NULL, key, ivec);
+	EVP_CIPHER_CTX_set_padding(des3->des3_ctx, 0);
+#else
 	EVP_CIPHER_CTX_init(&des3->des3_ctx);
 	EVP_EncryptInit_ex(&des3->des3_ctx, EVP_des_ede3_cbc(), NULL, key, ivec);
 	EVP_CIPHER_CTX_set_padding(&des3->des3_ctx, 0);
+#endif
 	return des3;
 }
 
@@ -103,23 +110,37 @@ CryptoDes3 crypto_des3_decrypt_init(const BYTE* key, c
 	CryptoDes3 des3 = malloc(sizeof(*des3));
 	if (!des3)
 		return NULL;
-
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	des3->des3_ctx = EVP_CIPHER_CTX_new();
+	EVP_CIPHER_CTX_init(des3->des3_ctx);
+	EVP_DecryptInit_ex(des3->des3_ctx, EVP_des_ede3_cbc(), NULL, key, ivec);
+	EVP_CIPHER_CTX_set_padding(des3->des3_ctx, 0);
+#else
 	EVP_CIPHER_CTX_init(&des3->des3_ctx);
 	EVP_DecryptInit_ex(&des3->des3_ctx, EVP_des_ede3_cbc(), NULL, key, ivec);
 	EVP_CIPHER_CTX_set_padding(&des3->des3_ctx, 0);
+#endif
 	return des3;
 }
 
 void crypto_des3_encrypt(CryptoDes3 des3, UINT32 length, const BYTE* in_data, BYTE* out_data)
 {
 	int len;
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	EVP_EncryptUpdate(des3->des3_ctx, out_data, &len, in_data, length);
+#else
 	EVP_EncryptUpdate(&des3->des3_ctx, out_data, &len, in_data, length);
+#endif
 }
 
 void crypto_des3_decrypt(CryptoDes3 des3, UINT32 length, const BYTE* in_data, BYTE* out_data)
 {
 	int len;
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	EVP_DecryptUpdate(des3->des3_ctx, out_data, &len, in_data, length);
+#else
 	EVP_DecryptUpdate(&des3->des3_ctx, out_data, &len, in_data, length);
+#endif
 
 	if (length != len)
 		abort(); /* TODO */
@@ -129,7 +150,12 @@ void crypto_des3_free(CryptoDes3 des3)
 {
 	if (des3 == NULL)
 		return;
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	EVP_CIPHER_CTX_cleanup(des3->des3_ctx);
+	EVP_CIPHER_CTX_free(des3->des3_ctx);
+#else
 	EVP_CIPHER_CTX_cleanup(&des3->des3_ctx);
+#endif
 	free(des3);
 }
 
@@ -139,28 +165,48 @@ CryptoHmac crypto_hmac_new(void)
 	if (!hmac)
 		return NULL;
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	hmac->hmac_ctx = HMAC_CTX_new();
+#else
 	HMAC_CTX_init(&hmac->hmac_ctx);
+#endif
 	return hmac;
 }
 
 void crypto_hmac_sha1_init(CryptoHmac hmac, const BYTE* data, UINT32 length)
 {
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	HMAC_Init_ex(hmac->hmac_ctx, data, length, EVP_sha1(), NULL);
+#else
 	HMAC_Init_ex(&hmac->hmac_ctx, data, length, EVP_sha1(), NULL);
+#endif
 }
 
 void crypto_hmac_md5_init(CryptoHmac hmac, const BYTE* data, UINT32 length)
 {
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	HMAC_Init_ex(hmac->hmac_ctx, data, length, EVP_md5(), NULL);
+#else
 	HMAC_Init_ex(&hmac->hmac_ctx, data, length, EVP_md5(), NULL);
+#endif
 }
 
 void crypto_hmac_update(CryptoHmac hmac, const BYTE* data, UINT32 length)
 {
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	HMAC_Update(hmac->hmac_ctx, data, length);
+#else
 	HMAC_Update(&hmac->hmac_ctx, data, length);
+#endif
 }
 
 void crypto_hmac_final(CryptoHmac hmac, BYTE* out_data, UINT32 length)
 {
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	HMAC_Final(hmac->hmac_ctx, out_data, &length);
+#else
 	HMAC_Final(&hmac->hmac_ctx, out_data, &length);
+#endif
 }
 
 void crypto_hmac_free(CryptoHmac hmac)
@@ -168,7 +214,11 @@ void crypto_hmac_free(CryptoHmac hmac)
 	if (hmac == NULL)
 		return;
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	HMAC_CTX_free(hmac->hmac_ctx);
+#else
 	HMAC_CTX_cleanup(&hmac->hmac_ctx);
+#endif
 	free(hmac);
 }
 
@@ -236,7 +286,11 @@ static int crypto_rsa_common(const BYTE* input, int le
 	BYTE* input_reverse;
 	BYTE* modulus_reverse;
 	BYTE* exponent_reverse;
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	BIGNUM *mod, *exp, *x, *y;
+#else
 	BIGNUM mod, exp, x, y;
+#endif
 
 	input_reverse = (BYTE*) malloc(2 * key_length + exponent_size);
 	if (!input_reverse)
@@ -254,6 +308,18 @@ static int crypto_rsa_common(const BYTE* input, int le
 	ctx = BN_CTX_new();
 	if (!ctx)
 		goto out_free_input_reverse;
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	mod = BN_new();
+	exp = BN_new();
+	x = BN_new();
+	y = BN_new();
+
+	BN_bin2bn(modulus_reverse, key_length, mod);
+	BN_bin2bn(exponent_reverse, exponent_size, exp);
+	BN_bin2bn(input_reverse, length, x);
+	BN_mod_exp(y, x, exp, mod, ctx);
+	output_length = BN_bn2bin(y, output);
+#else
 	BN_init(&mod);
 	BN_init(&exp);
 	BN_init(&x);
@@ -263,17 +329,24 @@ static int crypto_rsa_common(const BYTE* input, int le
 	BN_bin2bn(exponent_reverse, exponent_size, &exp);
 	BN_bin2bn(input_reverse, length, &x);
 	BN_mod_exp(&y, &x, &exp, &mod, ctx);
-
 	output_length = BN_bn2bin(&y, output);
+#endif
 	crypto_reverse(output, output_length);
 
 	if (output_length < (int) key_length)
 		memset(output + output_length, 0, key_length - output_length);
 
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+	BN_free(y);
+	BN_clear_free(x);
+	BN_free(exp);
+	BN_free(mod);
+#else
 	BN_free(&y);
 	BN_clear_free(&x);
 	BN_free(&exp);
 	BN_free(&mod);
+#endif
 	BN_CTX_free(ctx);
 
 out_free_input_reverse:
