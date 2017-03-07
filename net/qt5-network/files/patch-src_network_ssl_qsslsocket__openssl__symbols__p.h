* Boilerplate for SSL_CTX_set1_groups() used in qsslcontext_openssl.cpp
*
* check macro is defined instead of version, LibreSSL < 2.5 doesn't have SSL_CTRL_GET_SERVER_TMP_KEY
*
--- src/network/ssl/qsslsocket_openssl_symbols_p.h.orig	2016-12-01 08:17:04 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols_p.h
@@ -487,11 +487,12 @@ void q_EC_KEY_free(EC_KEY *ecdh);
 size_t q_EC_get_builtin_curves(EC_builtin_curve *r, size_t nitems);
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
 int q_EC_curve_nist2nid(const char *name);
+int q_SSL_CTX_set1_groups(SSL_CTX *a, int *b, int c);
 #endif // OPENSSL_VERSION_NUMBER >= 0x10002000L
 #endif // OPENSSL_NO_EC
-#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+#if defined(SSL_CTRL_GET_SERVER_TMP_KEY)
 #define q_SSL_get_server_tmp_key(ssl, key) q_SSL_ctrl((ssl), SSL_CTRL_GET_SERVER_TMP_KEY, 0, (char *)key)
-#endif // OPENSSL_VERSION_NUMBER >= 0x10002000L
+#endif // defined(SSL_CTRL_GET_SERVER_TMP_KEY)
 
 // PKCS#12 support
 int q_PKCS12_parse(PKCS12 *p12, const char *pass, EVP_PKEY **pkey, X509 **cert, STACK_OF(X509) **ca);
