--- dtls.c.orig	2019-07-04 06:42:58 UTC
+++ dtls.c
@@ -491,7 +491,7 @@ void *dtlslistener(void *arg) {
             BIO_set_fd(SSL_get_rbio(conf->tlsconf->dtlssslprep), s, BIO_NOCLOSE);
         }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000
+#if (OPENSSL_VERSION_NUMBER < 0x10100000) || defined(LIBRESSL_VERSION_NUMBER)
         if(DTLSv1_listen(conf->tlsconf->dtlssslprep, &from) > 0) {
 #else
         if(DTLSv1_listen(conf->tlsconf->dtlssslprep, (BIO_ADDR *)&from) > 0) {
