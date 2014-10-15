--- svnup.c.orig	2014-09-06 03:16:15.000000000 +0200
+++ svnup.c	2014-10-08 15:11:07.593705013 +0200
@@ -355,7 +355,7 @@
 		SSL_load_error_strings();
 		connection->ctx = SSL_CTX_new(SSLv23_client_method());
 		SSL_CTX_set_mode(connection->ctx, SSL_MODE_AUTO_RETRY);
-		SSL_CTX_set_options(connection->ctx, SSL_OP_ALL | SSL_OP_NO_TICKET | SSL_OP_NO_TLSv1);
+		SSL_CTX_set_options(connection->ctx, SSL_OP_ALL | SSL_OP_NO_TICKET);
 
 		if ((connection->ssl = SSL_new(connection->ctx)) == NULL)
 			err(EXIT_FAILURE, "reset_connection: SSL_new");
