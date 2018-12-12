--- src/modules/tls/tls_bio.c.orig	2018-11-28 11:08:42.000000000 +0100
+++ src/modules/tls/tls_bio.c	2018-12-12 18:28:16.580475000 +0100
@@ -63,7 +63,7 @@
 static long tls_bio_mbuf_ctrl(BIO* b, int cmd, long arg1, void* arg2);
 
 
-#if OPENSSL_VERSION_NUMBER < 0x010100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x010100000L || ( defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x2070000fL )
 static BIO_METHOD tls_mbuf_method = {
 	BIO_TYPE_TLS_MBUF,	/* type */
 	"sr_tls_mbuf",		/* name */
@@ -109,7 +109,7 @@
 /** returns a custom tls_mbuf BIO. */
 BIO_METHOD* tls_BIO_mbuf(void)
 {
-#if OPENSSL_VERSION_NUMBER < 0x010100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x010100000L || ( defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x2070000fL )
 	return &tls_mbuf_method;
 #else
 	if(tls_mbuf_method != NULL) {
