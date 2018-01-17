--- winpr/libwinpr/crypto/hash.c.orig	2017-11-28 14:26:30 UTC
+++ winpr/libwinpr/crypto/hash.c
@@ -179,7 +179,7 @@ BOOL winpr_HMAC_Init(WINPR_HMAC_CTX* ctx
 	if (!evp || !hmac)
 		return FALSE;
 
-#if (OPENSSL_VERSION_NUMBER < 0x10000000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10000000L) || defined(LIBRESSL_VERSION_NUMBER)
 	HMAC_Init_ex(hmac, key, keylen, evp, NULL); /* no return value on OpenSSL 0.9.x */
 	return TRUE;
 #else
@@ -215,7 +215,7 @@ BOOL winpr_HMAC_Update(WINPR_HMAC_CTX* c
 {
 #if defined(WITH_OPENSSL)
 	HMAC_CTX* hmac = (HMAC_CTX*) ctx;
-#if (OPENSSL_VERSION_NUMBER < 0x10000000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10000000L) || defined(LIBRESSL_VERSION_NUMBER)
 	HMAC_Update(hmac, input, ilen); /* no return value on OpenSSL 0.9.x */
 	return TRUE;
 #else
@@ -247,7 +247,7 @@ BOOL winpr_HMAC_Final(WINPR_HMAC_CTX* ct
 
 #if defined(WITH_OPENSSL)
 	hmac = (HMAC_CTX*) ctx;
-#if (OPENSSL_VERSION_NUMBER < 0x10000000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10000000L) || defined(LIBRESSL_VERSION_NUMBER)
 	HMAC_Final(hmac, output, NULL); /* no return value on OpenSSL 0.9.x */
 	return TRUE;
 #else
