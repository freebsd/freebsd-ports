--- modules/ssl/ssl_private.h.orig	2017-04-03 11:39:20 UTC
+++ modules/ssl/ssl_private.h
@@ -123,6 +123,16 @@
 #define MODSSL_SSL_METHOD_CONST
 #endif
 
+#if defined(LIBRESSL_VERSION_NUMBER)
+/* Missing from LibreSSL */
+#define SSL_CTRL_SET_MIN_PROTO_VERSION          123
+#define SSL_CTRL_SET_MAX_PROTO_VERSION          124
+#define SSL_CTX_set_min_proto_version(ctx, version) \
+        SSL_CTX_ctrl(ctx, SSL_CTRL_SET_MIN_PROTO_VERSION, version, NULL)
+#define SSL_CTX_set_max_proto_version(ctx, version) \
+        SSL_CTX_ctrl(ctx, SSL_CTRL_SET_MAX_PROTO_VERSION, version, NULL)
+#endif
+
 #if defined(OPENSSL_FIPS)
 #define HAVE_FIPS
 #endif
@@ -136,7 +146,7 @@
 #endif
 
 /* session id constness */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #define IDCONST
 #else
 #define IDCONST const
@@ -199,7 +209,7 @@
 
 #endif /* !defined(OPENSSL_NO_TLSEXT) && defined(SSL_set_tlsext_host_name) */
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #define BN_get_rfc2409_prime_768   get_rfc2409_prime_768
 #define BN_get_rfc2409_prime_1024  get_rfc2409_prime_1024
 #define BN_get_rfc3526_prime_1536  get_rfc3526_prime_1536
@@ -219,7 +229,7 @@ void init_bio_methods(void);
 void free_bio_methods(void);
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10002000L
+#if OPENSSL_VERSION_NUMBER < 0x10002000L || defined(LIBRESSL_VERSION_NUMBER)
 #define X509_STORE_CTX_get0_store(x) (x->ctx)
 #endif
 
@@ -934,7 +944,7 @@ char        *ssl_util_readfilter(server_
                                  const char * const *);
 BOOL         ssl_util_path_check(ssl_pathcheck_t, const char *, apr_pool_t *);
 #if APR_HAS_THREADS
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 void         ssl_util_thread_setup(apr_pool_t *);
 #endif
 void         ssl_util_thread_id_setup(apr_pool_t *);
