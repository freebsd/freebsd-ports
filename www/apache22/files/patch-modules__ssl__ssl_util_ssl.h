--- modules/ssl/ssl_util_ssl.h.orig	2012-08-17 17:30:46 UTC
+++ modules/ssl/ssl_util_ssl.h
@@ -89,7 +89,11 @@ char       *SSL_X509_NAME_to_string(apr_
 BOOL        SSL_X509_getCN(apr_pool_t *, X509 *, char **);
 BOOL        SSL_X509_INFO_load_file(apr_pool_t *, STACK_OF(X509_INFO) *, const char *);
 BOOL        SSL_X509_INFO_load_path(apr_pool_t *, STACK_OF(X509_INFO) *, const char *);
+#ifndef HAVE_SSL_CTX_USE_CERTIFICATE_CHAIN
 int         SSL_CTX_use_certificate_chain(SSL_CTX *, char *, int, modssl_read_bio_cb_fn *);
+#else
+int         _SSL_CTX_use_certificate_chain(SSL_CTX *, char *, int, modssl_read_bio_cb_fn *);
+#endif
 char       *SSL_SESSION_id2sz(unsigned char *, int, char *, int);
 
 /** util functions for OpenSSL+sslc compat */
