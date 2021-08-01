Drop after FreeBSD 13.0/12.2 EOL around 2022-05-30

ld: error: undefined symbol: __atomic_is_lock_free
>>> referenced by threads_pthread.c
>>>               libfips-lib-threads_pthread.o:(CRYPTO_atomic_or) in archive providers/libfips.a
>>> referenced by threads_pthread.c
>>>               libfips-lib-threads_pthread.o:(CRYPTO_atomic_load) in archive providers/libfips.a

--- crypto/threads_pthread.c.orig	2021-07-29 14:50:29 UTC
+++ crypto/threads_pthread.c
@@ -15,6 +15,9 @@
 
 #if defined(__sun)
 # include <atomic.h>
+#elif defined(__clang__) && defined(__i386__) && __clang_major__ < 12
+/* Until https://github.com/llvm/llvm-project/commit/00530dee5d12 */
+#define __atomic_is_lock_free(size, ptr) ((void)(ptr), size <= sizeof(void *))
 #endif
 
 #if defined(OPENSSL_THREADS) && !defined(CRYPTO_TDEBUG) && !defined(OPENSSL_SYS_WINDOWS)
