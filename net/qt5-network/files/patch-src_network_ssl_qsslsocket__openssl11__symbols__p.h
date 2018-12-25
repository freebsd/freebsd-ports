For LibreSSL, redefine OPENSSL_STACK to use the native stack_st.
Also redefine DSA_bits() to a LibreSSL-native routine.

Redefine SSL stack functions to their proper symbols in LibreSSL.

--- src/network/ssl/qsslsocket_openssl11_symbols_p.h.orig	2018-12-03 11:15:26 UTC
+++ src/network/ssl/qsslsocket_openssl11_symbols_p.h
@@ -75,21 +75,49 @@
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
+#else
 int q_OPENSSL_sk_num(OPENSSL_STACK *a);
 void q_OPENSSL_sk_pop_free(OPENSSL_STACK *a, void (*b)(void *));
 OPENSSL_STACK *q_OPENSSL_sk_new_null();
 void q_OPENSSL_sk_push(OPENSSL_STACK *st, void *data);
 void q_OPENSSL_sk_free(OPENSSL_STACK *a);
 void * q_OPENSSL_sk_value(OPENSSL_STACK *a, int b);
+#endif
 int q_SSL_session_reused(SSL *a);
 unsigned long q_SSL_CTX_set_options(SSL_CTX *ctx, unsigned long op);
 int q_OPENSSL_init_ssl(uint64_t opts, const OPENSSL_INIT_SETTINGS *settings);
@@ -112,8 +140,13 @@ int q_DH_bits(DH *dh);
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
