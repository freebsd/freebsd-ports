--- src/ssl.c.orig	2017-02-09 11:46:11 UTC
+++ src/ssl.c
@@ -38,7 +38,7 @@ tcn_pass_cb_t tcn_password_callback;
 static jclass byteArrayClass;
 static jclass stringClass;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 /* Global reference to the pool used by the dynamic mutexes */
 static apr_pool_t *dynlockpool = NULL;
 
@@ -201,7 +201,7 @@ static const jint supported_ssl_opts = 0
 #endif
      | 0;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 /* OpenSSL Pre-1.1.0 compatibility */
 /* Taken from OpenSSL 1.1.0 snapshot 20160410 */
 int DH_set0_pqg(DH *dh, BIGNUM *p, BIGNUM *q, BIGNUM *g)
@@ -303,7 +303,7 @@ DH *SSL_get_dh_params(unsigned keylen)
     return NULL; /* impossible to reach. */
 }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 static void init_bio_methods(void);
 static void free_bio_methods(void);
 #endif
@@ -338,7 +338,7 @@ static apr_status_t ssl_init_cleanup(voi
                          tcn_password_callback.cb.obj);
     }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     free_bio_methods();
 #endif
     free_dh_params();
@@ -357,7 +357,7 @@ static apr_status_t ssl_init_cleanup(voi
     ENGINE_cleanup();
 #endif
     CRYPTO_cleanup_all_ex_data();
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     ERR_remove_thread_state(NULL);
 #endif
 
@@ -393,7 +393,7 @@ static ENGINE *ssl_try_load_engine(const
  * To ensure thread-safetyness in OpenSSL
  */
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 static apr_thread_mutex_t **ssl_lock_cs;
 static int                  ssl_lock_num_locks;
 
@@ -439,7 +439,7 @@ static unsigned long ssl_thread_id(void)
 #endif
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #if ! (defined(WIN32) || defined(WIN64))
 void SSL_thread_exit(void) {
     ERR_remove_thread_state(NULL);
@@ -757,7 +757,7 @@ TCN_IMPLEMENT_CALL(jint, SSL, initialize
 #endif
     OPENSSL_load_builtin_modules();
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #if ! (defined(WIN32) || defined(WIN64))
     err = apr_threadkey_private_create(&thread_exit_key, _ssl_thread_exit,
                                        tcn_global_pool);
@@ -811,7 +811,7 @@ TCN_IMPLEMENT_CALL(jint, SSL, initialize
     SSL_init_app_data2_3_idx();
 
     init_dh_params();
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     init_bio_methods();
 #endif
 
@@ -973,7 +973,7 @@ static int jbs_new(BIO *bi)
     j->refcount  = 1;
     BIO_set_shutdown(bi, 1);
     BIO_set_init(bi, 0);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     /* No setter method for OpenSSL 1.1.0 available,
      * but I can't find any functional use of the
      * "num" field there either.
@@ -1109,7 +1109,7 @@ static long jbs_ctrl(BIO *b, int cmd, lo
     return ret;
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 static BIO_METHOD jbs_methods = {
     BIO_TYPE_FILE,
     "Java Callback",
@@ -1145,7 +1145,7 @@ static void free_bio_methods(void)
 
 static BIO_METHOD *BIO_jbs()
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     return(&jbs_methods);
 #else
     return jbs_methods;
