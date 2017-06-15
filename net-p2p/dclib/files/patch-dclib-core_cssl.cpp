--- dclib/core/cssl.cpp.orig	2013-09-07 16:26:31.000000000 +0200
+++ dclib/core/cssl.cpp	2013-09-07 16:28:11.000000000 +0200
@@ -86,7 +86,7 @@
 /** */
 SSL_CTX * CSSL::InitClientCTX()
 {
-	SSL_METHOD *method;
+	const SSL_METHOD *method;
 	SSL_CTX *ctx = NULL;
 
 	method = SSLv23_client_method();		/* Create new client-method instance */
@@ -109,7 +109,7 @@
 /** */
 SSL_CTX * CSSL::InitServerCTX()
 {
-	SSL_METHOD *method;
+	const SSL_METHOD *method;
 	SSL_CTX *ctx = NULL;
 
 	method = SSLv23_server_method();		/* Create new client-method instance */
@@ -130,7 +130,7 @@
 /** */
 SSL_CTX * CSSL::NewTLSv1ClientCTX()
 {
-	SSL_METHOD * method = TLSv1_client_method();
+	const SSL_METHOD * method = TLSv1_client_method();
 	SSL_CTX * ctx = NULL;
 	
 	if ( method != NULL )
@@ -149,7 +149,7 @@
 /** */
 SSL_CTX * CSSL::NewTLSv1ServerCTX()
 {
-	SSL_METHOD * method = TLSv1_server_method();
+	const SSL_METHOD * method = TLSv1_server_method();
 	SSL_CTX * ctx = NULL;
 	
 	if ( method != NULL )
