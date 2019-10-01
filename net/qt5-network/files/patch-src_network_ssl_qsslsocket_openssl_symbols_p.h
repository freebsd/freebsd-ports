--- src/network/ssl/qsslsocket_openssl_symbols_p.h.orig	2019-10-01 07:47:06 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols_p.h
@@ -72,6 +72,12 @@
 #include "qsslsocket_openssl_p.h"
 #include <QtCore/qglobal.h>
 
+#if defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER >= 0x20700000L
+# define TLS1_2_VERSION 0x0303
+# define TLS_MAX_VERSION TLS1_2_VERSION
+# define TLS_ANY_VERSION 0x10000
+#endif
+
 #if QT_CONFIG(ocsp)
 #include "qocsp_p.h"
 #endif
@@ -372,7 +378,7 @@ int q_SSL_CTX_use_PrivateKey(SSL_CTX *a, EVP_PKEY *b);
 int q_SSL_CTX_use_RSAPrivateKey(SSL_CTX *a, RSA *b);
 int q_SSL_CTX_use_PrivateKey_file(SSL_CTX *a, const char *b, int c);
 X509_STORE *q_SSL_CTX_get_cert_store(const SSL_CTX *a);
-#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L  && !defined(LIBRESSL_VERSION_NUMBER)
 SSL_CONF_CTX *q_SSL_CONF_CTX_new();
 void q_SSL_CONF_CTX_free(SSL_CONF_CTX *a);
 void q_SSL_CONF_CTX_set_ssl_ctx(SSL_CONF_CTX *a, SSL_CTX *b);
