# libressl support
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=196139
# https://issues.apache.org/bugzilla/show_bug.cgi?id=57375

--- modules/ssl/ssl_util_ssl.h.orig	2014-03-02 20:20:14 UTC
+++ modules/ssl/ssl_util_ssl.h
@@ -69,7 +69,11 @@ BOOL        SSL_X509_getIDs(apr_pool_t *
 BOOL        SSL_X509_match_name(apr_pool_t *, X509 *, const char *, BOOL, server_rec *);
 BOOL        SSL_X509_INFO_load_file(apr_pool_t *, STACK_OF(X509_INFO) *, const char *);
 BOOL        SSL_X509_INFO_load_path(apr_pool_t *, STACK_OF(X509_INFO) *, const char *);
+#ifndef HAVE_SSL_CTX_USE_CERTIFICATE_CHAIN
 int         SSL_CTX_use_certificate_chain(SSL_CTX *, char *, int, pem_password_cb *);
+#else
+int         _SSL_CTX_use_certificate_chain(SSL_CTX *, char *, int, pem_password_cb *);
+#endif
 char       *SSL_SESSION_id2sz(unsigned char *, int, char *, int);
 
 #endif /* __SSL_UTIL_SSL_H__ */
