--- include/ssl_private.h.orig	2020-04-24 19:24:44 UTC
+++ include/ssl_private.h
@@ -241,7 +241,7 @@
 #define TLS_server_method                SSLv23_server_method
 #endif /* OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER) */
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L && !defined(LIBRESSL_VERSION_NUMBER)
 #define HAVE_KEYLOG_CALLBACK
 #endif
 
