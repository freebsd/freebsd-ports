Boilerplate for SSL_CTX_set1_groups() used in qsslcontext_openssl.cpp.
*
* Fix for libressl atter openssl111 API change
* Definitions for TLS_VERSIONS needed for  qsslcontext_openssl11.cpp (QSslContext::initSslContext)
*
--- src/network/ssl/qsslsocket_openssl_symbols_p.h.orig	2018-10-21 17:04:11 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols_p.h
@@ -74,6 +74,13 @@
 
 QT_BEGIN_NAMESPACE
 
+#if defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER >= 0x20700000L
+# define TLS1_2_VERSION 0x0303
+# define TLS_MAX_VERSION TLS1_2_VERSION
+# define TLS_ANY_VERSION 0x10000
+#endif
+
+
 #define DUMMYARG
 
 #if !defined QT_LINKED_OPENSSL
@@ -356,7 +363,7 @@ int q_SSL_CTX_use_PrivateKey(SSL_CTX *a,
 int q_SSL_CTX_use_RSAPrivateKey(SSL_CTX *a, RSA *b);
 int q_SSL_CTX_use_PrivateKey_file(SSL_CTX *a, const char *b, int c);
 X509_STORE *q_SSL_CTX_get_cert_store(const SSL_CTX *a);
-#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(LIBRESSL_VERSION_NUMBER)
 SSL_CONF_CTX *q_SSL_CONF_CTX_new();
 void q_SSL_CONF_CTX_free(SSL_CONF_CTX *a);
 void q_SSL_CONF_CTX_set_ssl_ctx(SSL_CONF_CTX *a, SSL_CTX *b);
@@ -468,6 +475,9 @@ void q_EC_KEY_free(EC_KEY *ecdh);
 size_t q_EC_get_builtin_curves(EC_builtin_curve *r, size_t nitems);
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
 int q_EC_curve_nist2nid(const char *name);
+#if defined(LIBRESSL_VERSION_NUMBER)
+int q_SSL_CTX_set1_groups(SSL_CTX *a, int *b, int c);
+#endif // defined(LIBRESSL_VERSION_NUMBER)
 #endif // OPENSSL_VERSION_NUMBER >= 0x10002000L
 #endif // OPENSSL_NO_EC
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
