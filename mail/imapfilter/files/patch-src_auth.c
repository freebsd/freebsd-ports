--- src/auth.c.orig	2017-11-19 09:38:24 UTC
+++ src/auth.c
@@ -20,7 +20,7 @@ auth_cram_md5(const char *user, const char *pass, unsi
 	unsigned char *resp, *buf, *out;
 	unsigned char md[EVP_MAX_MD_SIZE], mdhex[EVP_MAX_MD_SIZE * 2 + 1];
 	unsigned int mdlen;
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL && !defined(LIBRESSL_VERSION_NUMBER)
+#ifdef HAVE_OPAQUE_STRUCTS && !defined(LIBRESSL_VERSION_NUMBER)
 	HMAC_CTX *ctx;
 #else
 	HMAC_CTX ctx;
@@ -32,7 +32,7 @@ auth_cram_md5(const char *user, const char *pass, unsi
 
 	EVP_DecodeBlock(resp, chal, strlen((char *)(chal)));
 
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL && !defined(LIBRESSL_VERSION_NUMBER)
+#ifdef HAVE_OPAQUE_STRUCTS && !defined(LIBRESSL_VERSION_NUMBER)
 	ctx = HMAC_CTX_new();
 	HMAC_Init_ex(ctx, (const unsigned char *)pass, strlen(pass),
 	    EVP_md5(), NULL);
