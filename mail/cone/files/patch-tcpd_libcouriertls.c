--- tcpd/libcouriertls.c.orig	2011-06-20 03:13:54 UTC
+++ tcpd/libcouriertls.c
@@ -552,11 +552,16 @@ SSL_CTX *tls_create(int isserver, const 
 		protocol="SSL23";
 
 	ctx=SSL_CTX_new(protocol && strcmp(protocol, "SSL3") == 0
-			? SSLv3_method():
+			? SSLv23_method():
 			protocol && strcmp(protocol, "SSL23") == 0
 			? SSLv23_method():
 			TLSv1_method());
-
+	if (strcmp(protocol, "SSL3") == 0)
+		SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2 | SSL_OP_NO_TLSv1
+#ifdef OPENSSL_NO_TLSv1_2
+		| SSL_OP_NO_TLSv1_1 | SSL_OP_NO_TLSv1_2
+#endif
+		);
 	if (!ctx)
 	{
 		free(info_copy);
