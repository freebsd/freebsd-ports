--- modules/ssl/ssl_engine_init.c.orig	2017-04-03 11:39:20 UTC
+++ modules/ssl/ssl_engine_init.c
@@ -47,7 +47,7 @@ APR_IMPLEMENT_OPTIONAL_HOOK_RUN_ALL(ssl,
 #define KEYTYPES "RSA or DSA"
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 /* OpenSSL Pre-1.1.0 compatibility */
 /* Taken from OpenSSL 1.1.0 snapshot 20160410 */
 static int DH_set0_pqg(DH *dh, BIGNUM *p, BIGNUM *q, BIGNUM *g)
@@ -257,7 +257,7 @@ apr_status_t ssl_init_Module(apr_pool_t 
 #endif
     }
 
-#if APR_HAS_THREADS && OPENSSL_VERSION_NUMBER < 0x10100000L
+#if APR_HAS_THREADS && ( OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER) )
     ssl_util_thread_setup(p);
 #endif
 
@@ -380,7 +380,7 @@ apr_status_t ssl_init_Module(apr_pool_t 
     modssl_init_app_data2_idx(); /* for modssl_get_app_data2() at request time */
 
     init_dh_params();
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     init_bio_methods();
 #endif
 
@@ -1301,7 +1301,7 @@ static apr_status_t ssl_init_server_cert
      * or configure NIST P-256 (required to enable ECDHE for earlier versions)
      * ECDH is always enabled in 1.1.0 unless excluded from SSLCipherList
      */
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
     else {
 #if defined(SSL_CTX_set_ecdh_auto)
         SSL_CTX_set_ecdh_auto(mctx->ssl_ctx, 1);
@@ -2011,7 +2011,7 @@ apr_status_t ssl_init_ModuleKill(void *d
 
     }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     free_bio_methods();
 #endif
     free_dh_params();
