--- include/ssl_private.h.orig	2014-10-17 14:50:34 UTC
+++ include/ssl_private.h
@@ -316,7 +316,11 @@ DH         *SSL_dh_get_param_from_file(c
 RSA        *SSL_callback_tmp_RSA(SSL *, int, int);
 DH         *SSL_callback_tmp_DH(SSL *, int, int);
 void        SSL_callback_handshake(const SSL *, int, int);
+#ifndef LIBRESSL_VERSION_NUMBER
 int         SSL_CTX_use_certificate_chain(SSL_CTX *, const char *, int);
+#else
+int         _SSL_CTX_use_certificate_chain(SSL_CTX *, const char *, int);
+#endif
 int         SSL_callback_SSL_verify(int, X509_STORE_CTX *);
 int         SSL_rand_seed(const char *file);
 
