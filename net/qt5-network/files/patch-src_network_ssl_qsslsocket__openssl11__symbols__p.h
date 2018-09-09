--- src/network/ssl/qsslsocket_openssl11_symbols_p.h.orig	2018-02-08 18:24:48 UTC
+++ src/network/ssl/qsslsocket_openssl11_symbols_p.h
@@ -75,15 +75,44 @@
 #error "You are not supposed to use this header file, include qsslsocket_openssl_symbols_p.h instead"
 #endif
 
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
+#define q_SSL_CTX_set_options(ctx,op) q_SSL_CTX_ctrl((ctx),SSL_CTRL_OPTIONS,(op),NULL)
+#define q_SSL_session_reused(ssl) q_SSL_ctrl((ssl),SSL_CTRL_GET_SESSION_REUSED,0,NULL)
+#else
 int q_OPENSSL_sk_num(OPENSSL_STACK *a);
 void q_OPENSSL_sk_pop_free(OPENSSL_STACK *a, void (*b)(void *));
 OPENSSL_STACK *q_OPENSSL_sk_new_null();
@@ -92,6 +121,7 @@ void q_OPENSSL_sk_free(OPENSSL_STACK *a)
 void * q_OPENSSL_sk_value(OPENSSL_STACK *a, int b);
 int q_SSL_session_reused(SSL *a);
 unsigned long q_SSL_CTX_set_options(SSL_CTX *ctx, unsigned long op);
+#endif
 int q_OPENSSL_init_ssl(uint64_t opts, const OPENSSL_INIT_SETTINGS *settings);
 size_t q_SSL_get_client_random(SSL *a, unsigned char *out, size_t outlen);
 size_t q_SSL_SESSION_get_master_key(const SSL_SESSION *session, unsigned char *out, size_t outlen);
@@ -102,7 +132,11 @@ const SSL_METHOD *q_TLS_server_method();
 ASN1_TIME *q_X509_getm_notBefore(X509 *a);
 ASN1_TIME *q_X509_getm_notAfter(X509 *a);
 
+#ifdef LIBRESSL_VERSION_NUMBER
+#define q_X509_get_version(x509) q_ASN1_INTEGER_get((x509)->cert_info->version)
+#else
 long q_X509_get_version(X509 *a);
+#endif
 EVP_PKEY *q_X509_get_pubkey(X509 *a);
 void q_X509_STORE_set_verify_cb(X509_STORE *ctx, X509_STORE_CTX_verify_cb verify_cb);
 STACK_OF(X509) *q_X509_STORE_CTX_get0_chain(X509_STORE_CTX *ctx);
@@ -112,8 +146,13 @@ int q_DH_bits(DH *dh);
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
