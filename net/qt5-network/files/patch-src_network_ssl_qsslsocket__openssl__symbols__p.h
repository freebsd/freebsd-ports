* Boilerplate for SSL_CTX_set1_groups() used in qsslcontext_openssl.cpp
*
* check macro is defined instead of version, LibreSSL < 2.5 doesn't have SSL_CTRL_GET_SERVER_TMP_KEY
*
--- src/network/ssl/qsslsocket_openssl_symbols_p.h.orig	2018-01-16 06:53:43 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols_p.h
@@ -228,7 +228,7 @@ int q_BIO_read(BIO *a, void *b, int c);
 Q_AUTOTEST_EXPORT BIO_METHOD *q_BIO_s_mem();
 Q_AUTOTEST_EXPORT int q_BIO_write(BIO *a, const void *b, int c);
 int q_BN_num_bits(const BIGNUM *a);
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if !defined(BN_is_word)
 int q_BN_is_word(BIGNUM *a, BN_ULONG w);
 #else
 // BN_is_word is implemented purely as a
@@ -511,11 +511,14 @@ void q_EC_KEY_free(EC_KEY *ecdh);
 size_t q_EC_get_builtin_curves(EC_builtin_curve *r, size_t nitems);
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
 int q_EC_curve_nist2nid(const char *name);
+#if defined(LIBRESSL_VERSION_NUMBER)
+int q_SSL_CTX_set1_groups(SSL_CTX *a, int *b, int c);
+#endif // defined(LIBRESSL_VERSION_NUMBER)
 #endif // OPENSSL_VERSION_NUMBER >= 0x10002000L
 #endif // OPENSSL_NO_EC
-#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+#if defined(SSL_CTRL_GET_SERVER_TMP_KEY)
 #define q_SSL_get_server_tmp_key(ssl, key) q_SSL_ctrl((ssl), SSL_CTRL_GET_SERVER_TMP_KEY, 0, (char *)key)
-#endif // OPENSSL_VERSION_NUMBER >= 0x10002000L
+#endif // defined(SSL_CTRL_GET_SERVER_TMP_KEY)
 
 // PKCS#12 support
 int q_PKCS12_parse(PKCS12 *p12, const char *pass, EVP_PKEY **pkey, X509 **cert, STACK_OF(X509) **ca);
