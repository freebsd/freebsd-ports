--- main/tcptls.c.orig	2015-04-08 18:53:07.000000000 +0200
+++ main/tcptls.c	2015-09-23 21:30:28.092457300 +0200
@@ -768,10 +768,13 @@ static int __ssl_setup(struct ast_tls_co
 			cfg->ssl_ctx = SSL_CTX_new(SSLv2_client_method());
 		} else
 #endif
+#ifndef OPENSSL_NO_SSL3
 		if (ast_test_flag(&cfg->flags, AST_SSL_SSLV3_CLIENT)) {
 			ast_log(LOG_WARNING, "Usage of SSLv3 is discouraged due to known vulnerabilities. Please use 'tlsv1' or leave the TLS method unspecified!\n");
 			cfg->ssl_ctx = SSL_CTX_new(SSLv3_client_method());
-		} else if (ast_test_flag(&cfg->flags, AST_SSL_TLSV1_CLIENT)) {
+		} else 
+#endif
+		if (ast_test_flag(&cfg->flags, AST_SSL_TLSV1_CLIENT)) {
 			cfg->ssl_ctx = SSL_CTX_new(TLSv1_client_method());
 		} else {
 			disable_ssl = 1;
