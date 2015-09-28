--- tcpd/libcouriertls.c.orig	2015-09-26 18:02:40 UTC
+++ tcpd/libcouriertls.c
@@ -552,10 +552,11 @@ SSL_CTX *tls_create(int isserver, const 
 		protocol="SSL23";
 
 	ctx=SSL_CTX_new(protocol && strcmp(protocol, "SSL3") == 0
-			? SSLv3_method():
+			? SSLv23_method():
 			protocol && strcmp(protocol, "SSL23") == 0
 			? SSLv23_method():
 			TLSv1_method());
+	SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv3 | SSL_OP_NO_SSLv2);
 
 	if (!ctx)
 	{
