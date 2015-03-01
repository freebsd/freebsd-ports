--- modules/ssl/ssl_util_ssl.c.orig	2012-08-17 19:30:46.000000000 +0200
+++ modules/ssl/ssl_util_ssl.c	2015-02-28 10:30:48.557501618 +0100
@@ -492,7 +492,11 @@
  * format, possibly followed by a sequence of CA certificates that
  * should be sent to the peer in the SSL Certificate message.
  */
+#ifndef HAVE_SSL_CTX_USE_CERTIFICATE_CHAIN
 int SSL_CTX_use_certificate_chain(
+#else
+int _SSL_CTX_use_certificate_chain(
+#endif
     SSL_CTX *ctx, char *file, int skipfirst, modssl_read_bio_cb_fn *cb)
 {
     BIO *bio;
