--- ./mssl.c.orig	2013-03-19 20:10:16.000000000 +0100
+++ ./mssl.c	2013-03-20 11:55:44.000000000 +0100
@@ -165,8 +165,10 @@
 
 	SSL_CTX *ctx = SSL_CTX_new(meth);
 
+#ifdef SSL_OP_NO_COMPRESSION
 	if (!ask_compression)
 		SSL_CTX_set_options(ctx, SSL_OP_NO_COMPRESSION);
+#endif
 
 	return ctx;
 }
