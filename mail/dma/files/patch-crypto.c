--- ./crypto.c.orig	2012-01-03 13:54:05.000000000 +0000
+++ ./crypto.c	2012-01-24 22:57:41.000000000 +0000
@@ -80,7 +80,7 @@
 smtp_init_crypto(int fd, int feature)
 {
 	SSL_CTX *ctx = NULL;
-	const SSL_METHOD *meth = NULL;
+	SSL_METHOD *meth = NULL;
 	X509 *cert;
 	int error;
 
