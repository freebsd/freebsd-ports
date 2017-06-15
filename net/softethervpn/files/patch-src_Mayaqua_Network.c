--- src/Mayaqua/Network.c.orig	2017-01-12 14:15:02 UTC
+++ src/Mayaqua/Network.c
@@ -12983,7 +12983,11 @@ bool StartSSLEx(SOCK *sock, X *x, K *pri
 		{
 			if (client_tls == false)
 			{
+#ifndef OPENSSL_NO_SSL3_METHOD
 				SSL_CTX_set_ssl_version(ssl_ctx, SSLv3_method());
+#else
+				SSL_CTX_set_ssl_version(ssl_ctx, SSLv23_method());
+#endif
 			}
 			else
 			{
