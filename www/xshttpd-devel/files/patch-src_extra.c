--- src/extra.c.orig	2015-01-02 16:49:11 UTC
+++ src/extra.c
@@ -586,7 +586,7 @@ do_crypt(const char * const skey, const char * const i
 	const unsigned int	IVLEN = 16;
 	int		outlen,
 			tmplen;
-	EVP_CIPHER_CTX	ctx;
+	EVP_CIPHER_CTX	*ctx;
 	unsigned char	plain[16] = { 0 };
 	unsigned char	outbuf[1024];
 	char		*encrypted;
@@ -600,17 +600,17 @@ do_crypt(const char * const skey, const char * const i
 	}
 
 	/* init aes-128-cbc */
-	EVP_CIPHER_CTX_init(&ctx);
-	EVP_EncryptInit_ex(&ctx, EVP_aes_128_cbc(), NULL, key, outbuf /* iv */);
+	ctx = EVP_CIPHER_CTX_new();
+	EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, outbuf /* iv */);
 
-	if (!EVP_EncryptUpdate(&ctx, outbuf + outlen, &tmplen,
+	if (!EVP_EncryptUpdate(ctx, outbuf + outlen, &tmplen,
 				plain, sizeof(plain)))
 		return false;
 	outlen += tmplen;
-	if (!EVP_EncryptFinal_ex(&ctx, outbuf + outlen, &tmplen))
+	if (!EVP_EncryptFinal_ex(ctx, outbuf + outlen, &tmplen))
 		return false;
 	outlen += tmplen;
-	EVP_CIPHER_CTX_cleanup(&ctx);
+	EVP_CIPHER_CTX_free(ctx);
 
 	MALLOC(encrypted, char, outlen);
 	memcpy(encrypted, outbuf, outlen);
