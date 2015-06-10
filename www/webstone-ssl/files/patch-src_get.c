--- src/get.c.orig	2000-06-21 19:15:41 UTC
+++ src/get.c
@@ -169,27 +169,33 @@ get(char *loc, NETPORT port, char *url, 
       OpenSSL_add_all_algorithms();
       OpenSSL_add_ssl_algorithms();
 
-		if(ssl_version != NULL && strcasecmp(ssl_version, "SSLv23") == 0) {
-			if((ctx = SSL_CTX_new(SSLv23_client_method())) == NULL) {
-				ERR_print_errors_fp(stderr);
-				goto error;
-			}
-			D_PRINTF( "SSL version = SSLv23\n" );
-		}
-		else if(ssl_version != NULL && strcasecmp(ssl_version, "SSLv2") == 0) {
-			if((ctx = SSL_CTX_new(SSLv2_client_method())) == NULL) {
+#ifndef OPENSSL_NO_SSL3_METHOD
+		if(ssl_version != NULL && strcasecmp(ssl_version, "SSLv3") == 0) {
+			if((ctx = SSL_CTX_new(SSLv3_client_method())) == NULL) {
 				ERR_print_errors_fp(stderr);
 				goto error;
 			}
-			D_PRINTF( "SSL version = SSLv2\n" );
+			D_PRINTF( "SSL version = SSLv3\n" );
 		}
-		else {
-			if((ctx = SSL_CTX_new(SSLv3_client_method())) == NULL) {
+		else
+#endif
+		{
+			if((ctx = SSL_CTX_new(SSLv23_client_method())) == NULL) {
 				ERR_print_errors_fp(stderr);
 				goto error;
 			}
-			D_PRINTF( "SSL version = SSLv3\n" );
+			D_PRINTF( "SSL version = SSLv23\n" );
 		}
 		
 		/* set preferred cipher */
