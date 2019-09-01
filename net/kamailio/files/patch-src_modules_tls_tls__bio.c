--- src/modules/tls/tls_bio.c.orig	2019-08-14 09:43:03 UTC
+++ src/modules/tls/tls_bio.c
@@ -63,7 +63,7 @@ static int tls_bio_mbuf_puts(BIO* b, const char* s);
 static long tls_bio_mbuf_ctrl(BIO* b, int cmd, long arg1, void* arg2);
 
 
-#if OPENSSL_VERSION_NUMBER < 0x010100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x010100000L || ( defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x2070000fL )
 static BIO_METHOD tls_mbuf_method = {
 	BIO_TYPE_TLS_MBUF,	/* type */
 	"sr_tls_mbuf",		/* name */
@@ -109,7 +109,7 @@ static BIO_METHOD *tls_mbuf_method = NULL;
 /** returns a custom tls_mbuf BIO. */
 BIO_METHOD* tls_BIO_mbuf(void)
 {
-#if OPENSSL_VERSION_NUMBER < 0x010100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x010100000L || ( defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x2070000fL )
 	return &tls_mbuf_method;
 #else
 	if(tls_mbuf_method != NULL) {
