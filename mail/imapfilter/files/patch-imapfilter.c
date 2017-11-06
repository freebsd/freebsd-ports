--- src/imapfilter.c.orig	2017-02-27 08:19:40 UTC
+++ src/imapfilter.c
@@ -21,7 +21,7 @@
 
 extern buffer ibuf, obuf, nbuf, cbuf;
 extern regexp responses[];
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL || LIBRESSL_VERSION_NUMBER
 extern SSL_CTX *sslctx;
 #else
 extern SSL_CTX *ssl23ctx;
@@ -131,7 +131,7 @@ main(int argc, char *argv[])
 
 	SSL_library_init();
 	SSL_load_error_strings();
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL || LIBRESSL_VERSION_NUMBER
 	sslctx = SSL_CTX_new(TLS_method());
 #else
 	ssl23ctx = SSL_CTX_new(SSLv23_client_method());
@@ -152,7 +152,7 @@ main(int argc, char *argv[])
 		capath = opts.truststore;
 	else if (exists_file(opts.truststore))
 		cafile = opts.truststore;
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL || LIBRESSL_VERSION_NUMBER
 	if (sslctx)
 		SSL_CTX_load_verify_locations(sslctx, cafile, capath);
 #else
@@ -193,7 +193,7 @@ main(int argc, char *argv[])
 #endif
 	stop_lua();
 
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if OPENSSL_VERSION_NUMBER >= 0x1010000fL || LIBRESSL_VERSION_NUMBER
 	if (sslctx)
 		SSL_CTX_free(sslctx);
 #else
