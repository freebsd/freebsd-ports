--- src/sslutils.c.orig	2013-07-25 21:01:25 UTC
+++ src/sslutils.c
@@ -409,8 +409,13 @@ DH *SSL_callback_tmp_DH(SSL *ssl, int ex
  * format, possibly followed by a sequence of CA certificates that
  * should be sent to the peer in the SSL Certificate message.
  */
+#ifndef LIBRESSL_VERSION_NUMBER
 int SSL_CTX_use_certificate_chain(SSL_CTX *ctx, const char *file,
                                   int skipfirst)
+#else
+int _SSL_CTX_use_certificate_chain(SSL_CTX *ctx, const char *file,
+                                  int skipfirst)
+#endif
 {
     BIO *bio;
     X509 *x509;
