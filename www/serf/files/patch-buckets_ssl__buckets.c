--- buckets/ssl_buckets.c.orig	2016-06-30 15:45:07 UTC
+++ buckets/ssl_buckets.c
@@ -1156,7 +1156,7 @@ static void init_ssl_libraries(void)
         }
 #endif
 
-#ifdef USE_OPENSSL_1_1_API
+#if defined(USE_OPENSSL_1_1_API) && !defined(LIBRESSL_VERSION_NUMBER)
         OPENSSL_malloc_init();
 #else
         CRYPTO_malloc_init();
