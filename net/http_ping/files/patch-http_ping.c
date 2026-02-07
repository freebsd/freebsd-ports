--- http_ping.c.orig	2024-02-08 02:14:24 UTC
+++ http_ping.c
@@ -424,8 +424,8 @@ start_connection( void )
 	    {
 	    SSL_load_error_strings();
 	    SSLeay_add_ssl_algorithms();
-	    ssl_ctx = SSL_CTX_new( SSLv23_client_method() );
-	    SSL_CTX_set_options( ssl_ctx, SSL_OP_NO_SSLv2|SSL_OP_NO_SSLv3 );
+	    ssl_ctx = SSL_CTX_new( TLS_client_method() );
+	    SSL_CTX_set_min_proto_version( ssl_ctx, TLS1_VERSION );
 	    }
 	if ( ! RAND_status() )
 	    {
@@ -437,11 +437,13 @@ start_connection( void )
 	    }
 	ssl = SSL_new( ssl_ctx );
 	SSL_set_fd( ssl, conn_fd );
+	SSL_set_tlsext_host_name(ssl, url_host);
 	r = SSL_connect( ssl );
 	if ( r <= 0 )
 	    {
 	    (void) fprintf(
-		stderr, "%s: SSL connection failed - %d\n", argv0, r );
+		stderr, "%s: SSL connection failed - %d\n", argv0,
+		SSL_get_error(ssl, r));
 	    ERR_print_errors_fp( stderr );
 	    close_connection();
 	    return 0;
