--- buckets/ssl_buckets.c.orig	2016-06-30 15:45:07 UTC
+++ buckets/ssl_buckets.c
@@ -407,7 +407,7 @@ static int bio_bucket_destroy(BIO *bio)
 
 static long bio_bucket_ctrl(BIO *bio, int cmd, long num, void *ptr)
 {
-    long ret = 1;
+    long ret = 0;
 
     switch (cmd) {
     default:
@@ -415,6 +415,7 @@ static long bio_bucket_ctrl(BIO *bio, int cmd, long nu
         break;
     case BIO_CTRL_FLUSH:
         /* At this point we can't force a flush. */
+        ret = 1;
         break;
     case BIO_CTRL_PUSH:
     case BIO_CTRL_POP:
@@ -1156,7 +1157,7 @@ static void init_ssl_libraries(void)
         }
 #endif
 
-#ifdef USE_OPENSSL_1_1_API
+#if defined(USE_OPENSSL_1_1_API) && !defined(LIBRESSL_VERSION_NUMBER)
         OPENSSL_malloc_init();
 #else
         CRYPTO_malloc_init();
