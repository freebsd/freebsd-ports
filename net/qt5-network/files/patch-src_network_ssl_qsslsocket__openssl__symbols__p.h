Boilerplate for SSL_CTX_set1_groups() used in qsslcontext_openssl.cpp.
--- src/network/ssl/qsslsocket_openssl_symbols_p.h.orig	2018-02-08 18:24:48 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols_p.h
@@ -454,6 +454,9 @@ void q_EC_KEY_free(EC_KEY *ecdh);
 size_t q_EC_get_builtin_curves(EC_builtin_curve *r, size_t nitems);
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
 int q_EC_curve_nist2nid(const char *name);
+#if defined(LIBRESSL_VERSION_NUMBER)
+int q_SSL_CTX_set1_groups(SSL_CTX *a, int *b, int c);
+#endif // defined(LIBRESSL_VERSION_NUMBER)
 #endif // OPENSSL_VERSION_NUMBER >= 0x10002000L
 #endif // OPENSSL_NO_EC
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
