--- pvkread.c.orig	2000-07-03 00:02:30 UTC
+++ pvkread.c
@@ -64,10 +64,10 @@
 #include "pvk.h"
 
 static int read_word(BIO *in, unsigned short *dat);
-static int read_dword(BIO *in, unsigned long *dat);
-static unsigned long get_dword(unsigned char **p);
+static int read_dword(BIO *in, uint32_t *dat);
+static uint32_t get_dword(unsigned char **p);
 static BIGNUM *lend2BN(unsigned char **nptr, int len);
-static int scan_magic(BIO *in, unsigned long *magic);
+static int scan_magic(BIO *in, uint32_t *magic);
 
 static int read_word(BIO *in, unsigned short *dat)
 {
@@ -77,7 +77,7 @@ static int read_word(BIO *in, unsigned short *dat)
 	return 1;
 }
 
-static int read_dword(BIO *in, unsigned long *dat)
+static int read_dword(BIO *in, uint32_t *dat)
 {
 	unsigned char buf[4];
 	if (BIO_read(in, buf, 4) != 4) return 0;
@@ -85,9 +85,9 @@ static int read_dword(BIO *in, unsigned long *dat)
 	return 1;
 }
 
-static unsigned long get_dword(unsigned char **p)
+static uint32_t get_dword(unsigned char **p)
 {
-	unsigned long ret;
+	uint32_t ret;
 	unsigned char *buf;
 	buf = *p;
 	ret = buf[0] + (buf[1] << 8) + (buf[2] << 16) + (buf[3] << 24);
@@ -95,7 +95,7 @@ static unsigned long get_dword(unsigned char **p)
 	return ret;
 }
 
-static int scan_magic(BIO *in, unsigned long *magic)
+static int scan_magic(BIO *in, uint32_t *magic)
 {
 	int i;
 	char dummy[4];
@@ -157,8 +157,8 @@ int pvk_read(BIO *in, PVK_DAT *pvk)
 
 int pvk_decrypt(PVK_DAT *pvk, char *pass)
 {
-	EVP_MD_CTX ctx;
-	EVP_CIPHER_CTX cctx;
+	EVP_MD_CTX *ctx;
+	EVP_CIPHER_CTX *cctx;
 	unsigned char *buf;
 	unsigned char tmpkey[EVP_MAX_KEY_LENGTH];
 	int outlen;
@@ -171,18 +171,21 @@ int pvk_decrypt(PVK_DAT *pvk, char *pass)
 		PVKerr(PVK_F_PVK_DECRYPT,ERR_R_MALLOC_FAILURE);
 		return 0;
 	}
-	EVP_DigestInit(&ctx, EVP_sha1());
-	EVP_DigestUpdate(&ctx, pvk->salt, pvk->saltlen);
-	EVP_DigestUpdate(&ctx, pass, strlen(pass));
-	EVP_DigestFinal(&ctx, tmpkey, NULL);
-        EVP_DecryptInit(&cctx, EVP_rc4(), tmpkey, NULL);
-	EVP_DecryptUpdate(&cctx, buf, &outlen, pvk->key, pvk->keylen);
+	ctx = EVP_MD_CTX_new();
+	EVP_DigestInit(ctx, EVP_sha1());
+	EVP_DigestUpdate(ctx, pvk->salt, pvk->saltlen);
+	EVP_DigestUpdate(ctx, pass, strlen(pass));
+	EVP_DigestFinal(ctx, tmpkey, NULL);
+	EVP_MD_CTX_free(ctx);
+	cctx = EVP_CIPHER_CTX_new();
+	EVP_DecryptInit(cctx, EVP_rc4(), tmpkey, NULL);
+	EVP_DecryptUpdate(cctx, buf, &outlen, pvk->key, pvk->keylen);
 	if(strncmp(buf, "RSA2", 4)) {
                 /* Didn't work: try weak encryption */
                 memset(tmpkey+5, 0, 11);
-                EVP_DecryptFinal(&cctx, buf + outlen, &outlen);
-                EVP_DecryptInit(&cctx, EVP_rc4(), tmpkey, NULL);
-                EVP_DecryptUpdate(&cctx, buf, &outlen, pvk->key, pvk->keylen);
+                EVP_DecryptFinal(cctx, buf + outlen, &outlen);
+                EVP_DecryptInit(cctx, EVP_rc4(), tmpkey, NULL);
+                EVP_DecryptUpdate(cctx, buf, &outlen, pvk->key, pvk->keylen);
                 if(strncmp(buf, "RSA2", 4)) {
 			PVKerr(PVK_F_PVK_DECRYPT,PVK_R_DECRYPT_ERROR);
                         OPENSSL_free(buf);
@@ -190,7 +193,8 @@ int pvk_decrypt(PVK_DAT *pvk, char *pass)
                 } else pvk->encr = PVK_WEAK;
         } else pvk->encr = PVK_STRONG;
 	/* Not needed but do it to cleanup */
-	EVP_DecryptFinal(&cctx, buf + outlen, &outlen);
+	EVP_DecryptFinal(cctx, buf + outlen, &outlen);
+	EVP_CIPHER_CTX_free(cctx);
 	OPENSSL_free(pvk->key);
 	pvk->key = buf;
         memset(tmpkey, 0, EVP_MAX_KEY_LENGTH);
@@ -203,6 +207,7 @@ RSA *pvk2rsa (PVK_DAT *pvk)
 	RSA *rsa;
 	unsigned char *keytmp;
 	int pubexp, keylen, pvklen;
+	BIGNUM *e, *n, *p, *q, *dmp1, *dmq1, *iqmp, *d;
 	rsa = RSA_new();
 	if (!rsa) return NULL;
 	keytmp = pvk->key + 4;
@@ -216,15 +221,21 @@ RSA *pvk2rsa (PVK_DAT *pvk)
 
  	if (pvklen < ((keylen/2)* 9)) goto err;
 
-	if(!(rsa->e = BN_new ())) goto err;
-	BN_set_word (rsa->e, pubexp);
-	if(!(rsa->n = lend2BN (&keytmp, keylen))) goto err;
-	if(!(rsa->p = lend2BN (&keytmp, keylen/2))) goto err;
-	if(!(rsa->q = lend2BN (&keytmp, keylen/2))) goto err;
-	if(!(rsa->dmp1 = lend2BN (&keytmp, keylen/2))) goto err;
-	if(!(rsa->dmq1 = lend2BN (&keytmp, keylen/2))) goto err;
-	if(!(rsa->iqmp = lend2BN (&keytmp, keylen/2))) goto err;
-	if(!(rsa->d = lend2BN (&keytmp, keylen))) goto err;
+	if (!(e = BN_new())) goto err;
+	BN_set_word (e, pubexp);
+
+	if(!(n = lend2BN (&keytmp, keylen))) goto err;
+	if(!(p = lend2BN (&keytmp, keylen/2))) goto err;
+	if(!(q = lend2BN (&keytmp, keylen/2))) goto err;
+	if(!(dmp1 = lend2BN (&keytmp, keylen/2))) goto err;
+	if(!(dmq1 = lend2BN (&keytmp, keylen/2))) goto err;
+	if(!(iqmp = lend2BN (&keytmp, keylen/2))) goto err;
+	if(!(d = lend2BN (&keytmp, keylen))) goto err;
+
+	RSA_set0_key(rsa, n, e, d);
+	RSA_set0_factors(rsa, p, q);
+	RSA_set0_crt_params(rsa, dmp1, dmq1, iqmp);
+
 	return rsa;
 	err:
 	PVKerr(PVK_F_PVK2RSA,PVK_R_INVALID_PRIVATE_KEY_FORMAT);
