--- src/sthreads.c.orig	2016-05-03 18:35:03 UTC
+++ src/sthreads.c
@@ -45,7 +45,7 @@
 
 STUNNEL_RWLOCK stunnel_locks[STUNNEL_LOCKS];
 
-#if OPENSSL_VERSION_NUMBER<0x10100004L
+#if OPENSSL_VERSION_NUMBER<0x10100004L || defined(LIBRESSL_VERSION_NUMBER)
 #define CRYPTO_THREAD_lock_new() CRYPTO_get_new_dynlockid()
 #endif
 
@@ -203,7 +203,7 @@ int create_client(SOCKET ls, SOCKET s, C
 
 #ifdef USE_PTHREAD
 
-#if OPENSSL_VERSION_NUMBER<0x10100004L
+#if OPENSSL_VERSION_NUMBER<0x10100004L || defined(LIBRESSL_VERSION_NUMBER)
 
 struct CRYPTO_dynlock_value {
     pthread_rwlock_t rwlock;
@@ -263,16 +263,18 @@ unsigned long stunnel_thread_id(void) {
 #endif
 }
 
-#if OPENSSL_VERSION_NUMBER>=0x10000000L && OPENSSL_VERSION_NUMBER<0x10100004L
+#if OPENSSL_VERSION_NUMBER>=0x10000000L
+#if OPENSSL_VERSION_NUMBER<0x10100004L || defined(LIBRESSL_VERSION_NUMBER)
 NOEXPORT void threadid_func(CRYPTO_THREADID *tid) {
     CRYPTO_THREADID_set_numeric(tid, stunnel_thread_id());
 }
 #endif
+#endif
 
 int sthreads_init(void) {
     int i;
 
-#if OPENSSL_VERSION_NUMBER<0x10100004L
+#if OPENSSL_VERSION_NUMBER<0x10100004L || defined(LIBRESSL_VERSION_NUMBER)
     /* initialize the OpenSSL dynamic locking */
     CRYPTO_set_dynlock_create_callback(dyn_create_function);
     CRYPTO_set_dynlock_lock_callback(dyn_lock_function);
@@ -345,7 +347,7 @@ int create_client(SOCKET ls, SOCKET s, C
  * but it is unsupported on Windows XP (and earlier versions of Windows):
  * https://msdn.microsoft.com/en-us/library/windows/desktop/aa904937%28v=vs.85%29.aspx */
 
-#if OPENSSL_VERSION_NUMBER<0x10100004L
+#if OPENSSL_VERSION_NUMBER<0x10100004L || defined(LIBRESSL_VERSION_NUMBER)
 
 struct CRYPTO_dynlock_value {
     CRITICAL_SECTION mutex;
@@ -398,7 +400,7 @@ unsigned long stunnel_thread_id(void) {
 int sthreads_init(void) {
     int i;
 
-#if OPENSSL_VERSION_NUMBER<0x10100004L
+#if OPENSSL_VERSION_NUMBER<0x10100004L || defined(LIBRESSL_VERSION_NUMBER)
     /* initialize the OpenSSL dynamic locking */
     CRYPTO_set_dynlock_create_callback(dyn_create_function);
     CRYPTO_set_dynlock_lock_callback(dyn_lock_function);
