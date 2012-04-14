--- crypto.c.orig	2012-01-03 13:54:05.000000000 +0000
+++ crypto.c	2012-03-06 23:50:42.000000000 +0000
@@ -80,7 +80,11 @@ int
 smtp_init_crypto(int fd, int feature)
 {
 	SSL_CTX *ctx = NULL;
+#if (OPENSSL_VERSION_NUMBER >= 0x00909000L)
 	const SSL_METHOD *meth = NULL;
+#else
+	SSL_METHOD *meth = NULL;
+#endif
 	X509 *cert;
 	int error;
 
