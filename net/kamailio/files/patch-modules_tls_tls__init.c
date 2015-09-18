--- modules/tls/tls_init.c.orig	2015-07-20 15:16:26.000000000 +0200
+++ modules/tls/tls_init.c	2015-09-10 16:27:31.669141324 +0200
@@ -344,9 +344,11 @@ static void init_ssl_methods(void)
 	ssl_methods[TLS_USE_SSLv2 - 1] = SSLv2_method();
 #endif
 
+#ifndef OPENSSL_NO_SSL3
 	ssl_methods[TLS_USE_SSLv3_cli - 1] = SSLv3_client_method();
 	ssl_methods[TLS_USE_SSLv3_srv - 1] = SSLv3_server_method();
 	ssl_methods[TLS_USE_SSLv3 - 1] = SSLv3_method();
+#endif
 
 	ssl_methods[TLS_USE_TLSv1_cli - 1] = TLSv1_client_method();
 	ssl_methods[TLS_USE_TLSv1_srv - 1] = TLSv1_server_method();
