--- modules/ssl/mod_ssl.c.orig	2018-02-13 23:43:36 UTC
+++ modules/ssl/mod_ssl.c
@@ -398,7 +398,7 @@ static int ssl_hook_pre_config(apr_pool_
     /* We must register the library in full, to ensure our configuration
      * code can successfully test the SSL environment.
      */
-#if MODSSL_USE_OPENSSL_PRE_1_1_API
+#if MODSSL_USE_OPENSSL_PRE_1_1_API || defined(LIBRESSL_VERSION_NUMBER)
     (void)CRYPTO_malloc_init();
 #else
     OPENSSL_malloc_init();
