--- winpr/libwinpr/crypto/hash.c.orig	2017-08-05 09:37:24 UTC
+++ winpr/libwinpr/crypto/hash.c
@@ -178,7 +178,7 @@ BOOL winpr_HMAC_Init(WINPR_HMAC_CTX* ctx, WINPR_MD_TYP
 	if (!evp || !hmac)
 		return FALSE;
 
-#if (OPENSSL_VERSION_NUMBER < 0x10000000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10000000L) || defined(LIBRESSL_VERSION_NUMBER)
 	HMAC_Init_ex(hmac, key, keylen, evp, NULL); /* no return value on OpenSSL 0.9.x */
 	return TRUE;
 #else
@@ -214,7 +214,7 @@ BOOL winpr_HMAC_Update(WINPR_HMAC_CTX* ctx, const BYTE
 #if defined(WITH_OPENSSL)
 	HMAC_CTX* hmac = (HMAC_CTX*) ctx;
 
-#if (OPENSSL_VERSION_NUMBER < 0x10000000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10000000L) || defined(LIBRESSL_VERSION_NUMBER)
 	HMAC_Update(hmac, input, ilen); /* no return value on OpenSSL 0.9.x */
 	return TRUE;
 #else
@@ -244,7 +244,7 @@ BOOL winpr_HMAC_Final(WINPR_HMAC_CTX* ctx, BYTE* outpu
 
 #if defined(WITH_OPENSSL)
 	hmac = (HMAC_CTX*) ctx;
-#if (OPENSSL_VERSION_NUMBER < 0x10000000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10000000L) || defined(LIBRESSL_VERSION_NUMBER)
 	HMAC_Final(hmac, output, NULL); /* no return value on OpenSSL 0.9.x */
 	return TRUE;
 #else
