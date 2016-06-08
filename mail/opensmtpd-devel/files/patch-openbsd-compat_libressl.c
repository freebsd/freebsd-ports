--- openbsd-compat/libressl.c.orig	2015-02-01 23:01:01.000000000 +0100
+++ openbsd-compat/libressl.c	2015-02-28 15:43:27.948897301 +0100
@@ -68,6 +68,7 @@
 #include <openssl/pem.h>
 #include <openssl/ssl.h>
 
+#ifndef LIBRESSL_VERSION_NUMBER
 int
 SSL_CTX_use_certificate_chain(SSL_CTX *ctx, char *buf, off_t len)
 {
@@ -129,3 +130,4 @@
 		BIO_free(in);
 	return (ret);
 }
+#endif
