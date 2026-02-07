--- buckets/ssl_buckets.c.orig	2023-05-18 09:33:55 UTC
+++ buckets/ssl_buckets.c
@@ -1186,7 +1186,7 @@ static void init_ssl_libraries(void)
         }
 #endif
 
-#ifdef USE_OPENSSL_1_1_API
+#if defined(USE_OPENSSL_1_1_API) && !defined(LIBRESSL_VERSION_NUMBER)
         OPENSSL_malloc_init();
 #else
         CRYPTO_malloc_init();
