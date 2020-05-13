--- src/ssl.c.orig	2020-04-24 19:24:44 UTC
+++ src/ssl.c
@@ -367,11 +367,6 @@ static apr_status_t ssl_init_cleanup(void *data)
 #endif
     free_dh_params();
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
-    /* Openssl v1.1+ handles all termination automatically. Do
-     * nothing in this case.
-     */
-#else
     /*
      * Try to kill the internals of the SSL library.
      */
@@ -394,7 +389,6 @@ static apr_status_t ssl_init_cleanup(void *data)
 #if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     ERR_remove_thread_state(NULL);
 #endif
-#endif
 
 #ifdef HAVE_KEYLOG_CALLBACK
     if (key_log_file) {
@@ -764,14 +758,7 @@ TCN_IMPLEMENT_CALL(jint, SSL, initialize)(TCN_STDARGS,
         TCN_FREE_CSTRING(engine);
         return (jint)APR_SUCCESS;
     }
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
-    /* Openssl v1.1+ handles all initialisation automatically, apart
-     * from hints as to how we want to use the library.
-     *
-     * We tell openssl we want to include engine support.
-     */
-    OPENSSL_init_ssl(OPENSSL_INIT_ENGINE_ALL_BUILTIN, NULL);
-#else
+
     /* We must register the library in full, to ensure our configuration
      * code can successfully test the SSL environment.
      */
@@ -785,6 +772,7 @@ TCN_IMPLEMENT_CALL(jint, SSL, initialize)(TCN_STDARGS,
 #endif
     OPENSSL_load_builtin_modules();
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 #if ! (defined(WIN32) || defined(WIN64))
     err = apr_threadkey_private_create(&thread_exit_key, _ssl_thread_exit,
                                        tcn_global_pool);
