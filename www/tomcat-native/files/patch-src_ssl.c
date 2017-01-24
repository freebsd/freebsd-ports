--- src/ssl.c.orig	2016-04-19 10:08:10 UTC
+++ src/ssl.c
@@ -34,7 +34,7 @@ tcn_pass_cb_t tcn_password_callback;
 static jclass byteArrayClass;
 static jclass stringClass;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 /* Global reference to the pool used by the dynamic mutexes */
 static apr_pool_t *dynlockpool = NULL;
 
@@ -193,7 +193,7 @@ static const jint supported_ssl_opts = 0
 #endif
      | 0;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 /* OpenSSL Pre-1.1.0 compatibility */
 /* Taken from OpenSSL 1.1.0 snapshot 20160410 */
 int DH_set0_pqg(DH *dh, BIGNUM *p, BIGNUM *q, BIGNUM *g)
@@ -295,7 +295,7 @@ DH *SSL_get_dh_params(unsigned keylen)
     return NULL; /* impossible to reach. */
 }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 static void init_bio_methods(void);
 static void free_bio_methods(void);
 #endif
@@ -330,7 +330,7 @@ static apr_status_t ssl_init_cleanup(voi
                          tcn_password_callback.cb.obj);
     }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     free_bio_methods();
 #endif
     free_dh_params();
@@ -349,7 +349,7 @@ static apr_status_t ssl_init_cleanup(voi
     ENGINE_cleanup();
 #endif
     CRYPTO_cleanup_all_ex_data();
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     ERR_remove_thread_state(NULL);
 #else
     ERR_remove_thread_state();
@@ -387,7 +387,7 @@ static ENGINE *ssl_try_load_engine(const
  * To ensure thread-safetyness in OpenSSL
  */
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 static apr_thread_mutex_t **ssl_lock_cs;
 static int                  ssl_lock_num_locks;
 
@@ -427,7 +427,7 @@ static unsigned long ssl_thread_id(void)
 #endif
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 static void ssl_set_thread_id(CRYPTO_THREADID *id)
 {
     CRYPTO_THREADID_set_numeric(id, ssl_thread_id());
@@ -720,7 +720,7 @@ TCN_IMPLEMENT_CALL(jint, SSL, initialize
 #endif
     OPENSSL_load_builtin_modules();
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     /* Initialize thread support */
     ssl_thread_setup(tcn_global_pool);
 #endif
@@ -766,7 +766,7 @@ TCN_IMPLEMENT_CALL(jint, SSL, initialize
     SSL_init_app_data2_3_idx();
 
     init_dh_params();
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     init_bio_methods();
 #endif
 
@@ -928,7 +928,7 @@ static int jbs_new(BIO *bi)
     j->refcount  = 1;
     BIO_set_shutdown(bi, 1);
     BIO_set_init(bi, 0);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     /* No setter method for OpenSSL 1.1.0 available,
      * but I can't find any functional use of the
      * "num" field there either.
@@ -1064,7 +1064,7 @@ static long jbs_ctrl(BIO *b, int cmd, lo
     return ret;
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 static BIO_METHOD jbs_methods = {
     BIO_TYPE_FILE,
     "Java Callback",
@@ -1100,7 +1100,7 @@ static void free_bio_methods(void)
 
 static BIO_METHOD *BIO_jbs()
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     return(&jbs_methods);
 #else
     return jbs_methods;
