--- src/md_crypt.c.orig	2018-01-30 10:20:50 UTC
+++ src/md_crypt.c
@@ -471,7 +471,7 @@ apr_status_t md_pkey_gen(md_pkey_t **ppk
     }
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 
 #ifndef NID_tlsfeature
 #define NID_tlsfeature          1020
