$OpenBSD: patch-src_imapfilter_c,v 1.2 2015/07/18 23:11:01 sthen Exp $
--- src/imapfilter.c.orig	Mon Jun 29 02:33:17 2015
+++ src/imapfilter.c	Sat Jul 18 18:34:04 2015
@@ -21,7 +21,10 @@
 
 extern buffer ibuf, obuf, nbuf, cbuf;
 extern regexp responses[];
-extern SSL_CTX *ssl3ctx, *ssl23ctx, *tls1ctx;
+extern SSL_CTX *ssl23ctx, *tls1ctx;
+#ifndef OPENSSL_NO_SSL3_METHOD
+extern SSL_CTX *ssl3ctx;
+#endif
 #if OPENSSL_VERSION_NUMBER >= 0x01000100fL
 extern SSL_CTX *tls11ctx, *tls12ctx;
 #endif
@@ -52,7 +55,7 @@ main(int argc, char *argv[])
 	opts.config = NULL;
 	opts.oneline = NULL;
 	opts.debug = NULL;
-	opts.truststore = "/etc/ssl/certs";
+	opts.truststore = "/etc/ssl/cert.pem";
 
 	env.home = NULL;
 	env.pathmax = -1;
@@ -109,7 +112,9 @@ main(int argc, char *argv[])
 
 	SSL_library_init();
 	SSL_load_error_strings();
+#ifndef OPENSSL_NO_SSL3_METHOD
 	ssl3ctx = SSL_CTX_new(SSLv3_client_method());
+#endif
 	ssl23ctx = SSL_CTX_new(SSLv23_client_method());
 	tls1ctx = SSL_CTX_new(TLSv1_client_method());
 #if OPENSSL_VERSION_NUMBER >= 0x01000100fL
@@ -121,7 +126,9 @@ main(int argc, char *argv[])
 		capath = opts.truststore;
 	if (exists_file(opts.truststore))
 		cafile = opts.truststore;
+#ifndef OPENSSL_NO_SSL3_METHOD
 	SSL_CTX_load_verify_locations(ssl3ctx, cafile, capath);
+#endif
 	SSL_CTX_load_verify_locations(ssl23ctx, cafile, capath);
 	SSL_CTX_load_verify_locations(tls1ctx, cafile, capath);
 #if OPENSSL_VERSION_NUMBER >= 0x01000100fL
@@ -146,7 +153,9 @@ main(int argc, char *argv[])
 #endif
 	stop_lua();
 
+#ifndef OPENSSL_NO_SSL3_METHOD
 	SSL_CTX_free(ssl3ctx);
+#endif
 	SSL_CTX_free(ssl23ctx);
 	SSL_CTX_free(tls1ctx);
 #if OPENSSL_VERSION_NUMBER >= 0x01000100fL
