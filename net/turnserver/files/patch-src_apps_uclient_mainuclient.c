--- src/apps/uclient/mainuclient.c.orig	2015-09-30 07:05:14 UTC
+++ src/apps/uclient/mainuclient.c
@@ -483,9 +483,11 @@ int main(int argc, char **argv)
 		  root_tls_ctx[root_tls_ctx_num] = SSL_CTX_new(SSLv23_client_method());
 		  SSL_CTX_set_cipher_list(root_tls_ctx[root_tls_ctx_num], csuite);
 		  root_tls_ctx_num++;
+#ifndef OPENSSL_NO_SSL3 
 		  root_tls_ctx[root_tls_ctx_num] = SSL_CTX_new(SSLv3_client_method());
 		  SSL_CTX_set_cipher_list(root_tls_ctx[root_tls_ctx_num], csuite);
 		  root_tls_ctx_num++;
+#endif
 		  root_tls_ctx[root_tls_ctx_num] = SSL_CTX_new(TLSv1_client_method());
 		  SSL_CTX_set_cipher_list(root_tls_ctx[root_tls_ctx_num], csuite);
 		  root_tls_ctx_num++;
