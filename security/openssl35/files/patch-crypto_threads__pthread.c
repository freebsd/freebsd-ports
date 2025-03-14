--- crypto/threads_pthread.c.orig	2022-11-01 14:14:36 UTC
+++ crypto/threads_pthread.c
@@ -29,6 +29,10 @@
 #define BROKEN_CLANG_ATOMICS
 #endif
 
+#if defined(__FreeBSD__) && defined(__i386__)
+#define BROKEN_CLANG_ATOMICS
+#endif
+
 #if defined(OPENSSL_THREADS) && !defined(CRYPTO_TDEBUG) && !defined(OPENSSL_SYS_WINDOWS)
 
 # if defined(OPENSSL_SYS_UNIX)
