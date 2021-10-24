--- deps/openssl/openssl/crypto/threads_pthread.c.orig	2021-10-27 15:57:20 UTC
+++ deps/openssl/openssl/crypto/threads_pthread.c
@@ -188,7 +188,7 @@ int CRYPTO_THREAD_compare_id(CRYPTO_THREAD_ID a, CRYPT
 
 int CRYPTO_atomic_add(int *val, int amount, int *ret, CRYPTO_RWLOCK *lock)
 {
-# if defined(__GNUC__) && defined(__ATOMIC_ACQ_REL)
+# if defined(__GNUC__) && defined(__ATOMIC_ACQ_REL) && !defined(__i386__)
     if (__atomic_is_lock_free(sizeof(*val), val)) {
         *ret = __atomic_add_fetch(val, amount, __ATOMIC_ACQ_REL);
         return 1;
@@ -215,7 +215,7 @@ int CRYPTO_atomic_add(int *val, int amount, int *ret, 
 int CRYPTO_atomic_or(uint64_t *val, uint64_t op, uint64_t *ret,
                      CRYPTO_RWLOCK *lock)
 {
-# if defined(__GNUC__) && defined(__ATOMIC_ACQ_REL)
+# if defined(__GNUC__) && defined(__ATOMIC_ACQ_REL) && !defined(__i386__)
     if (__atomic_is_lock_free(sizeof(*val), val)) {
         *ret = __atomic_or_fetch(val, op, __ATOMIC_ACQ_REL);
         return 1;
@@ -240,7 +240,7 @@ int CRYPTO_atomic_or(uint64_t *val, uint64_t op, uint6
 
 int CRYPTO_atomic_load(uint64_t *val, uint64_t *ret, CRYPTO_RWLOCK *lock)
 {
-# if defined(__GNUC__) && defined(__ATOMIC_ACQUIRE)
+# if defined(__GNUC__) && defined(__ATOMIC_ACQUIRE) && !defined(__i386__)
     if (__atomic_is_lock_free(sizeof(*val), val)) {
         __atomic_load(val, ret, __ATOMIC_ACQUIRE);
         return 1;
