--- src/Mayaqua/Network.c.orig	2015-07-26 06:38:18 UTC
+++ src/Mayaqua/Network.c
@@ -12920,7 +12920,16 @@ bool StartSSLEx(SOCK *sock, X *x, K *pri
 		{
 			if (client_tls == false)
 			{
+#ifndef OPENSSL_NO_SSL3
 				SSL_CTX_set_ssl_version(ssl_ctx, SSLv3_method());
+#else
+				SSL_CTX_set_ssl_version(ssl_ctx, SSLv23_method());
+				SSL_CTX_set_options(ssl_ctx, SSL_OP_NO_SSLv2 | SSL_OP_NO_TLSv1
+#ifdef SSL_OP_NO_TLSv1_2
+				| SSL_OP_NO_TLSv1_1 | SSL_OP_NO_TLSv1_2
+#endif
+				);
+#endif
 			}
 			else
 			{
