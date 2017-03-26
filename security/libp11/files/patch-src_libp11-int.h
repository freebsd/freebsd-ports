--- src/libp11-int.h.orig	2017-01-26 21:19:45 UTC
+++ src/libp11-int.h
@@ -32,7 +32,7 @@
 extern void *C_LoadModule(const char *name, CK_FUNCTION_LIST_PTR_PTR);
 extern CK_RV C_UnloadModule(void *module);
 
-#if OPENSSL_VERSION_NUMBER < 0x10100004L
+#if OPENSSL_VERSION_NUMBER < 0x10100004L || defined(LIBRESSL_VERSION_NUMBER)
 typedef int PKCS11_RWLOCK;
 #else
 typedef CRYPTO_RWLOCK *PKCS11_RWLOCK;
@@ -144,7 +144,7 @@ typedef struct pkcs11_cert_private {
 #define PKCS11_DUP(s) \
 	pkcs11_strdup((char *) s, sizeof(s))
 
-#if OPENSSL_VERSION_NUMBER < 0x10100004L
+#if OPENSSL_VERSION_NUMBER < 0x10100004L || defined(LIBRESSL_VERSION_NUMBER)
 /* Emulate the OpenSSL 1.1 locking API for older OpenSSL versions */
 int CRYPTO_THREAD_lock_new();
 void CRYPTO_THREAD_lock_free(int);
