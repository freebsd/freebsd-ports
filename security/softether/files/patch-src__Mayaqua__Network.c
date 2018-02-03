--- src/Mayaqua/Network.c.orig	2016-05-03 06:16:53 UTC
+++ src/Mayaqua/Network.c
@@ -13025,10 +13025,15 @@
 		{
 			if (client_tls == false)
 			{
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#ifndef OPENSSL_NO_SSL3
 				SSL_CTX_set_ssl_version(ssl_ctx, SSLv3_method());
 #else
 				SSL_CTX_set_ssl_version(ssl_ctx, SSLv23_method());
+				SSL_CTX_set_options(ssl_ctx, SSL_OP_NO_SSLv2 | SSL_OP_NO_TLSv1
+#ifdef SSL_OP_NO_TLSv1_2
+				| SSL_OP_NO_TLSv1_1 | SSL_OP_NO_TLSv1_2
+#endif
+				);
 #endif
 			}
 			else
