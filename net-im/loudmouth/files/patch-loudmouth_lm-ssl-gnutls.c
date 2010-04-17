--- loudmouth/lm-ssl-gnutls.c.orig	2010-04-17 15:56:39.000000000 -0400
+++ loudmouth/lm-ssl-gnutls.c	2010-04-17 15:56:43.000000000 -0400
@@ -32,7 +32,7 @@
 
 #include <gnutls/x509.h>
 
-#define CA_PEM_FILE "/etc/ssl/certs/ca-certificates.crt"
+#define CA_PEM_FILE "%%LOCALBASE%%/share/certs/ca-root-nss.crt"
 
 struct _LmSSL {
 	LmSSLBase base;
@@ -200,6 +200,7 @@ _lm_ssl_begin (LmSSL *ssl, gint fd, cons
 		{ GNUTLS_CRT_X509, GNUTLS_CRT_OPENPGP, 0 };
 	const int compression_priority[] =
 		{ GNUTLS_COMP_DEFLATE, GNUTLS_COMP_NULL, 0 };
+	gnutls_priority_t priorities_cache;
 
 	gnutls_init (&ssl->gnutls_session, GNUTLS_CLIENT);
 	gnutls_set_default_priority (ssl->gnutls_session);
@@ -213,6 +214,8 @@ _lm_ssl_begin (LmSSL *ssl, gint fd, cons
 
 	gnutls_transport_set_ptr (ssl->gnutls_session,
 				  (gnutls_transport_ptr_t)(glong) fd);
+	gnutls_priority_init (&priorities_cache, "NONE:+VERS-TLS1.0:+AES-128-CBC:+RSA:+SHA1:+COMP-NULL:NORMAL:%COMPAT", NULL);
+	gnutls_priority_set (ssl->gnutls_session, priorities_cache);
 
 	ret = gnutls_handshake (ssl->gnutls_session);
 
