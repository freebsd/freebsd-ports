--- src/p11_misc.c.orig	2017-02-11 19:26:33 UTC
+++ src/p11_misc.c
@@ -43,7 +43,7 @@ char *pkcs11_strdup(char *mem, size_t si
  * CRYPTO dynlock wrappers: 0 is an invalid dynamic lock ID
  */
 
-#if OPENSSL_VERSION_NUMBER < 0x10100004L
+#if OPENSSL_VERSION_NUMBER < 0x10100004L || defined(LIBRESSL_VERSION_NUMBER)
 
 int CRYPTO_THREAD_lock_new()
 {
