--- src/prototypes.h.orig	2016-07-05 21:27:57 UTC
+++ src/prototypes.h
@@ -650,13 +650,13 @@ typedef enum {
 #endif /* OPENSSL_NO_DH */
     STUNNEL_LOCKS                           /* number of locks */
 } LOCK_TYPE;
-#if OPENSSL_VERSION_NUMBER < 0x10100004L
+#if OPENSSL_VERSION_NUMBER < 0x10100004L || defined(LIBRESSL_VERSION_NUMBER)
 typedef int STUNNEL_RWLOCK;
 #else
 typedef CRYPTO_RWLOCK *STUNNEL_RWLOCK;
 #endif
 extern STUNNEL_RWLOCK stunnel_locks[STUNNEL_LOCKS];
-#if OPENSSL_VERSION_NUMBER>=0x10100004L
+#if OPENSSL_VERSION_NUMBER>=0x10100004L && !defined(LIBRESSL_VERSION_NUMBER)
 #define CRYPTO_THREAD_read_unlock(type) CRYPTO_THREAD_unlock(type)
 #define CRYPTO_THREAD_write_unlock(type) CRYPTO_THREAD_unlock(type)
 #else
