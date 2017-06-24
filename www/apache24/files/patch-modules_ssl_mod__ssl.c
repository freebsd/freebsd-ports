--- modules/ssl/mod_ssl.c.orig	2017-04-03 11:39:20 UTC
+++ modules/ssl/mod_ssl.c
@@ -337,12 +337,12 @@ static apr_status_t ssl_cleanup_pre_conf
 #if HAVE_ENGINE_LOAD_BUILTIN_ENGINES
     ENGINE_cleanup();
 #endif
-#if OPENSSL_VERSION_NUMBER >= 0x1000200fL
+#if OPENSSL_VERSION_NUMBER >= 0x1000200fL && !defined(OPENSSL_NO_COMP)
     SSL_COMP_free_compression_methods();
 #endif
 
     /* Usually needed per thread, but this parent process is single-threaded */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #if OPENSSL_VERSION_NUMBER >= 0x1000000fL
     ERR_remove_thread_state(NULL);
 #else
@@ -383,14 +383,14 @@ static int ssl_hook_pre_config(apr_pool_
     /* Some OpenSSL internals are allocated per-thread, make sure they
      * are associated to the/our same thread-id until cleaned up.
      */
-#if APR_HAS_THREADS && OPENSSL_VERSION_NUMBER < 0x10100000L
+#if APR_HAS_THREADS && OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     ssl_util_thread_id_setup(pconf);
 #endif
 
     /* We must register the library in full, to ensure our configuration
      * code can successfully test the SSL environment.
      */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     CRYPTO_malloc_init();
 #else
     OPENSSL_malloc_init();
