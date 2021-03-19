--- pvkwrite.c.orig	2000-07-03 00:02:30 UTC
+++ pvkwrite.c
@@ -73,7 +73,7 @@ static int write_word(BIO *out, unsigned short dat)
 	return 1;
 }
 
-static int write_dword(BIO *out, unsigned long dat)
+static int write_dword(BIO *out, uint32_t dat)
 {
 	unsigned char buf[4];
 	buf[0] = dat & 0xff;
@@ -84,7 +84,7 @@ static int write_dword(BIO *out, unsigned long dat)
 	return 1;
 }
 
-static void put_dword(unsigned char **p, unsigned long dat)
+static void put_dword(unsigned char **p, uint32_t dat)
 {
 	unsigned char *buf;
 	buf = *p;
@@ -125,8 +125,8 @@ int pvk_write(BIO *out, PVK_DAT *pvk)
 
 int pvk_encrypt(PVK_DAT *pvk, char *pass, int encr)
 {
-	EVP_MD_CTX ctx;
-	EVP_CIPHER_CTX cctx;
+	EVP_MD_CTX *ctx;
+	EVP_CIPHER_CTX *cctx;
 	unsigned char *buf;
 	unsigned char tmpkey[EVP_MAX_KEY_LENGTH];
 	int outlen;
@@ -141,17 +141,21 @@ int pvk_encrypt(PVK_DAT *pvk, char *pass, int encr)
 		PVKerr(PVK_F_PVK_ENCRYPT,ERR_R_MALLOC_FAILURE);
 		return 0;
 	}
-	EVP_DigestInit(&ctx, EVP_sha1());
-	EVP_DigestUpdate(&ctx, pvk->salt, pvk->saltlen);
-	EVP_DigestUpdate(&ctx, pass, strlen(pass));
-	EVP_DigestFinal(&ctx, tmpkey, NULL);
+	ctx = EVP_MD_CTX_new();
+	EVP_DigestInit(ctx, EVP_sha1());
+	EVP_DigestUpdate(ctx, pvk->salt, pvk->saltlen);
+	EVP_DigestUpdate(ctx, pass, strlen(pass));
+	EVP_DigestFinal(ctx, tmpkey, NULL);
+	EVP_MD_CTX_free(ctx);
 
         if(encr == PVK_WEAK) memset(tmpkey + 5, 0, 11);
 
-	EVP_EncryptInit(&cctx, EVP_rc4(), tmpkey, NULL);
-	EVP_EncryptUpdate(&cctx, buf, &outlen, pvk->key, pvk->keylen);
+	cctx = EVP_CIPHER_CTX_new();
+	EVP_EncryptInit(cctx, EVP_rc4(), tmpkey, NULL);
+	EVP_EncryptUpdate(cctx, buf, &outlen, pvk->key, pvk->keylen);
 	/* Not needed but do it to cleanup */
-	EVP_EncryptFinal(&cctx, buf + outlen, &outlen);
+	EVP_EncryptFinal(cctx, buf + outlen, &outlen);
+	EVP_CIPHER_CTX_free(cctx);
 	OPENSSL_free(pvk->key);
 	pvk->key = buf;
         pvk->crypt = 1;
@@ -161,7 +165,7 @@ int pvk_encrypt(PVK_DAT *pvk, char *pass, int encr)
 }
 
 /* Convert bignum to little endian format */ 
-static int BN2lend (BIGNUM *num, unsigned char *p)
+static int BN2lend (const BIGNUM *num, unsigned char *p)
 {
 	int nbyte, i;
 	unsigned char c;
@@ -178,7 +182,7 @@ static int BN2lend (BIGNUM *num, unsigned char *p)
 
 /* Convert RSA key into PVK structure */
 
-int rsa2pvk(RSA *rsa, PVK_DAT *pvk, unsigned long alg)
+int rsa2pvk(RSA *rsa, PVK_DAT *pvk, uint32_t alg)
 {
 	int numbytes;
 	unsigned char *p;
@@ -202,7 +206,7 @@ int rsa2pvk(RSA *rsa, PVK_DAT *pvk, unsigned long alg)
         else if(pvk->keyalg == RSA_SIG) pvk->keytype = PVK_SIG;
 
 	/* Set up a private key blob */
-	numbytes = BN_num_bytes (rsa->n);
+	numbytes = BN_num_bytes (RSA_get0_n(rsa));
 	/* Allocate enough room for blob */
 	if (!(pvk->key = calloc(1, 12 + numbytes * 5))) {
 		PVKerr(PVK_F_RSA2PVK,ERR_R_MALLOC_FAILURE);
@@ -216,23 +220,23 @@ int rsa2pvk(RSA *rsa, PVK_DAT *pvk, unsigned long alg)
 	p+= 4;
 
 	put_dword(&p, numbytes << 3);	/* Number of bits */
-	put_dword(&p, BN_get_word(rsa->e)); /* Public exponent */
+	put_dword(&p, BN_get_word(RSA_get0_e(rsa))); /* Public exponent */
 
 	/* Convert each element */
 
-	BN2lend (rsa->n, p);
+	BN2lend (RSA_get0_n(rsa), p);
 	p += numbytes;
-	BN2lend (rsa->p, p);
+	BN2lend (RSA_get0_p(rsa), p);
 	p += numbytes/2;
-	BN2lend (rsa->q, p);
+	BN2lend (RSA_get0_q(rsa), p);
 	p += numbytes/2;
-	BN2lend (rsa->dmp1, p);
+	BN2lend (RSA_get0_dmp1(rsa), p);
 	p += numbytes/2;
-	BN2lend (rsa->dmq1, p);
+	BN2lend (RSA_get0_dmq1(rsa), p);
 	p += numbytes/2;
-	BN2lend (rsa->iqmp,p);
+	BN2lend (RSA_get0_iqmp(rsa), p);
 	p += numbytes/2;
-	BN2lend (rsa->d, p);
+	BN2lend (RSA_get0_d(rsa), p);
 	p += numbytes;
 	pvk->keylen = p - pvk->key + 8;
 	RAND_seed(pvk->key, pvk->keylen);
