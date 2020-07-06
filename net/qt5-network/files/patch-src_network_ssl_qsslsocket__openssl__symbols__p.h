--- src/network/ssl/qsslsocket_openssl_symbols_p.h.orig	2020-05-05 11:59:27 UTC
+++ src/network/ssl/qsslsocket_openssl_symbols_p.h
@@ -72,6 +72,14 @@
 #include "qsslsocket_openssl_p.h"
 #include <QtCore/qglobal.h>
 
+#if defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER >= 0x20700000L
+# define TLS1_2_VERSION 0x0303
+# define TLS_MAX_VERSION TLS1_2_VERSION
+# define TLS_ANY_VERSION 0x10000
+# define DTLS1_2_VERSION                 0xFEFD
+# define DTLS_MAX_VERSION                DTLS1_2_VERSION
+#endif
+
 #if QT_CONFIG(ocsp)
 #include "qocsp_p.h"
 #endif
@@ -225,22 +233,50 @@ QT_BEGIN_NAMESPACE
 // content of the header here. Later, can be better sorted/split into groups,
 // depending on the functionality.
 
+#if defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER >= 0x20700000L
+// LibreSSL 2.7 has stack_st but not OPENSSL_STACK
+typedef struct stack_st OPENSSL_STACK; /* Use STACK_OF(...) instead */
+// From the signature in LibreSSL
+#define OPENSSL_INIT_SETTINGS void
+// https://github.com/openssl/openssl/blob/master/include/openssl/x509_vfy.h#L63
+typedef int (*X509_STORE_CTX_verify_cb)(int, X509_STORE_CTX *);
+#endif
+
 const unsigned char * q_ASN1_STRING_get0_data(const ASN1_STRING *x);
 
 Q_AUTOTEST_EXPORT BIO *q_BIO_new(const BIO_METHOD *a);
 Q_AUTOTEST_EXPORT const BIO_METHOD *q_BIO_s_mem();
 
+#ifdef LIBRESSL_VERSION_NUMBER
+#define q_DSA_bits(dsa) q_BN_num_bits((dsa)->p)
+#else
 int q_DSA_bits(DSA *a);
+#endif
 int q_EVP_CIPHER_CTX_reset(EVP_CIPHER_CTX *c);
 Q_AUTOTEST_EXPORT int q_EVP_PKEY_up_ref(EVP_PKEY *a);
 int q_EVP_PKEY_base_id(EVP_PKEY *a);
 int q_RSA_bits(RSA *a);
+#ifdef LIBRESSL_VERSION_NUMBER
+int q_sk_num(OPENSSL_STACK *a);
+void q_sk_pop_free(OPENSSL_STACK *a, void (*b)(void *));
+OPENSSL_STACK *q_sk_new_null();
+void q_sk_push(OPENSSL_STACK *st, void *data);
+void q_sk_free(OPENSSL_STACK *a);
+void * q_sk_value(OPENSSL_STACK *a, int b);
+#define q_OPENSSL_sk_num(a) q_sk_num(a)
+#define q_OPENSSL_sk_pop_free(a, b) q_sk_pop_free(a, b)
+#define q_OPENSSL_sk_new_null() q_sk_new_null()
+#define q_OPENSSL_sk_push(a, b) q_sk_push(a, b)
+#define q_OPENSSL_sk_free q_sk_free
+#define q_OPENSSL_sk_value(a, b) q_sk_value(a, b)
+#else
 Q_AUTOTEST_EXPORT int q_OPENSSL_sk_num(OPENSSL_STACK *a);
 Q_AUTOTEST_EXPORT void q_OPENSSL_sk_pop_free(OPENSSL_STACK *a, void (*b)(void *));
 Q_AUTOTEST_EXPORT OPENSSL_STACK *q_OPENSSL_sk_new_null();
 Q_AUTOTEST_EXPORT void q_OPENSSL_sk_push(OPENSSL_STACK *st, void *data);
 Q_AUTOTEST_EXPORT void q_OPENSSL_sk_free(OPENSSL_STACK *a);
 Q_AUTOTEST_EXPORT void * q_OPENSSL_sk_value(OPENSSL_STACK *a, int b);
+#endif
 int q_SSL_session_reused(SSL *a);
 unsigned long q_SSL_CTX_set_options(SSL_CTX *ctx, unsigned long op);
 int q_OPENSSL_init_ssl(uint64_t opts, const OPENSSL_INIT_SETTINGS *settings);
@@ -266,8 +302,13 @@ int q_DH_bits(DH *dh);
 # define q_SSL_load_error_strings() q_OPENSSL_init_ssl(OPENSSL_INIT_LOAD_SSL_STRINGS \
                                                        | OPENSSL_INIT_LOAD_CRYPTO_STRINGS, NULL)
 
+#ifdef LIBRESSL_VERSION_NUMBER
+#define q_SKM_sk_num(type, st) ((int (*)(const STACK_OF(type) *))q_sk_num)(st)
+#define q_SKM_sk_value(type, st,i) ((type * (*)(const STACK_OF(type) *, int))q_sk_value)(st, i)
+#else
 #define q_SKM_sk_num(type, st) ((int (*)(const STACK_OF(type) *))q_OPENSSL_sk_num)(st)
 #define q_SKM_sk_value(type, st,i) ((type * (*)(const STACK_OF(type) *, int))q_OPENSSL_sk_value)(st, i)
+#endif
 
 #define q_OPENSSL_add_all_algorithms_conf()  q_OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_CIPHERS \
                                                                    | OPENSSL_INIT_ADD_ALL_DIGESTS \
@@ -494,12 +535,14 @@ int q_SSL_CTX_use_PrivateKey(SSL_CTX *a, EVP_PKEY *b);
 int q_SSL_CTX_use_RSAPrivateKey(SSL_CTX *a, RSA *b);
 int q_SSL_CTX_use_PrivateKey_file(SSL_CTX *a, const char *b, int c);
 X509_STORE *q_SSL_CTX_get_cert_store(const SSL_CTX *a);
+#if !defined(LIBRESSL_VERSION_NUMBER)
 SSL_CONF_CTX *q_SSL_CONF_CTX_new();
 void q_SSL_CONF_CTX_free(SSL_CONF_CTX *a);
 void q_SSL_CONF_CTX_set_ssl_ctx(SSL_CONF_CTX *a, SSL_CTX *b);
 unsigned int q_SSL_CONF_CTX_set_flags(SSL_CONF_CTX *a, unsigned int b);
 int q_SSL_CONF_CTX_finish(SSL_CONF_CTX *a);
 int q_SSL_CONF_cmd(SSL_CONF_CTX *a, const char *b, const char *c);
+#endif
 void q_SSL_free(SSL *a);
 STACK_OF(SSL_CIPHER) *q_SSL_get_ciphers(const SSL *a);
 const SSL_CIPHER *q_SSL_get_current_cipher(SSL *a);
