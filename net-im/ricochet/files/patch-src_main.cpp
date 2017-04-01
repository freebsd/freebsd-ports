--- src/main.cpp.orig	2016-11-04 22:05:33 UTC
+++ src/main.cpp
@@ -86,7 +86,7 @@ int main(int argc, char *argv[])
     initTranslation();
 
     /* Initialize OpenSSL's allocator */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     CRYPTO_malloc_init();
 #else
     OPENSSL_malloc_init();
