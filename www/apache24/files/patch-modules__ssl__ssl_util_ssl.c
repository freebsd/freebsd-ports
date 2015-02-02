# libressl support
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=196139
# https://issues.apache.org/bugzilla/show_bug.cgi?id=57375

--- modules/ssl/ssl_util_ssl.c.orig	2015-01-12 13:31:16 UTC
+++ modules/ssl/ssl_util_ssl.c
@@ -473,7 +473,11 @@ EC_GROUP *ssl_ec_GetParamFromFile(const 
  * format, possibly followed by a sequence of CA certificates that
  * should be sent to the peer in the SSL Certificate message.
  */
+#ifndef HAVE_SSL_CTX_USE_CERTIFICATE_CHAIN
 int SSL_CTX_use_certificate_chain(
+#else
+int _SSL_CTX_use_certificate_chain(
+#endif
     SSL_CTX *ctx, char *file, int skipfirst, pem_password_cb *cb)
 {
     BIO *bio;
