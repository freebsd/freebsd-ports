--- src/Mayaqua/Network.c.orig	2015-09-28 15:42:29 UTC
+++ src/Mayaqua/Network.c
@@ -12920,7 +12920,12 @@ bool StartSSLEx(SOCK *sock, X *x, K *pri
 		{
 			if (client_tls == false)
 			{
+			  #ifndef OPENSSL_NO_SSL3
 				SSL_CTX_set_ssl_version(ssl_ctx, SSLv3_method());
+			  #else
+				SSL_CTX_set_ssl_version(ssl_ctx, SSLv23_method());
+				SSL_CTX_set_options(ssl_ctx, SSL_OP_NO_SSLv3 | SSL_OP_NO_SSLv2);
+			  #endif
 			}
 			else
 			{
