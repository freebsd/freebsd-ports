--- ptstream.c.orig	2012-01-23 18:13:41 UTC
+++ ptstream.c
@@ -151,7 +151,11 @@ int stream_enable_ssl(PTSTREAM *pts) {
 	
 	/* Initialise the connection */
 	SSLeay_add_ssl_algorithms();
+#ifndef OPENSSL_NO_SSL3
 	meth = SSLv3_client_method();
+#else
+	meth = SSLv23_client_method();
+#endif
 	SSL_load_error_strings();
 
 	ctx = SSL_CTX_new (meth);
