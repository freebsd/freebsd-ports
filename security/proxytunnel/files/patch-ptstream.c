--- ptstream.c.orig	2008-02-26 23:27:27 UTC
+++ ptstream.c
@@ -151,7 +151,7 @@ int stream_enable_ssl(PTSTREAM *pts) {
 	
 	/* Initialise the connection */
 	SSLeay_add_ssl_algorithms();
-	meth = SSLv3_client_method();
+	meth = SSLv23_client_method();
 	SSL_load_error_strings();
 
 	ctx = SSL_CTX_new (meth);
