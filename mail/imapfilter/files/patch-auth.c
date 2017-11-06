--- src/auth.c.orig	2017-02-27 08:30:09 UTC
+++ src//auth.c
@@ -20,7 +20,7 @@ auth_cram_md5(const char *user, const ch
 	unsigned char *resp, *buf, *out;
 	unsigned char md[EVP_MAX_MD_SIZE], mdhex[EVP_MAX_MD_SIZE * 2 + 1];
 	unsigned int mdlen;
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#ifdef HAVE_OPAQUE_STRUCTS
 	HMAC_CTX *ctx;
 #else
 	HMAC_CTX ctx;
@@ -32,7 +32,7 @@ auth_cram_md5(const char *user, const ch
 
 	EVP_DecodeBlock(resp, chal, strlen((char *)(chal)));
 
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#ifdef HAVE_OPAQUE_STRUCTS
 	ctx = HMAC_CTX_new();
 	HMAC_Init_ex(ctx, (const unsigned char *)pass, strlen(pass),
 	    EVP_md5(), NULL);
