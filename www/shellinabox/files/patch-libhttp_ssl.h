--- libhttp/ssl.h.orig	2016-11-09 19:40:33 UTC
+++ libhttp/ssl.h
@@ -57,6 +57,7 @@
 #include <openssl/bio.h>
 #include <openssl/err.h>
 #include <openssl/ssl.h>
+#include <openssl/safestack.h>
 #else
 #undef HAVE_OPENSSL
 typedef struct BIO        BIO;
@@ -77,6 +78,17 @@ typedef struct X509       X509;
 #endif
 
 #if defined(HAVE_DLOPEN)
+#if !defined(DEFAULT_LIBCRYPTO_SO) || !defined(DEFAULT_LIBSSL_SO)
+#undef DEFAULT_LIBCRYPTO_SO
+#undef DEFAULT_LIBSSL_SO
+#ifdef SHLIB_VERSION_NUMBER
+#define DEFAULT_LIBCRYPTO_SO "libcrypto.so." SHLIB_VERSION_NUMBER
+#define DEFAULT_LIBSSL_SO "libssl.so." SHLIB_VERSION_NUMBER
+#else
+#define DEFAULT_LIBCRYPTO_SO "libcrypto.so"
+#define DEFAULT_LIBSSL_SO "libssl.so"
+#endif
+#endif
 extern long    (*x_BIO_ctrl)(BIO *, int, long, void *);
 extern BIO_METHOD *(*x_BIO_f_buffer)(void);
 extern void    (*x_BIO_free_all)(BIO *);
@@ -99,6 +111,9 @@ extern SSL_CTX*(*x_SSL_CTX_new)(SSL_METHOD *);
 extern int     (*x_SSL_CTX_set_cipher_list)(SSL_CTX *, const char *);
 extern void    (*x_SSL_CTX_set_info_callback)(SSL_CTX *,
                                               void (*)(const SSL *, int, int));
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+extern unsigned long (*x_SSL_CTX_set_options)(SSL_CTX *, unsigned long);
+#endif
 extern int     (*x_SSL_CTX_use_PrivateKey_file)(SSL_CTX *, const char *, int);
 extern int     (*x_SSL_CTX_use_PrivateKey_ASN1)(int, SSL_CTX *,
                                                 const unsigned char *, long);
@@ -112,7 +127,9 @@ extern void   *(*x_SSL_get_ex_data)(const SSL *, int);
 extern BIO    *(*x_SSL_get_rbio)(const SSL *);
 extern const char *(*x_SSL_get_servername)(const SSL *, int);
 extern BIO    *(*x_SSL_get_wbio)(const SSL *);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 extern int     (*x_SSL_library_init)(void);
+#endif
 extern SSL    *(*x_SSL_new)(SSL_CTX *);
 extern int     (*x_SSL_read)(SSL *, void *, int);
 extern SSL_CTX*(*x_SSL_set_SSL_CTX)(SSL *, SSL_CTX *);
@@ -121,10 +138,16 @@ extern void    (*x_SSL_set_bio)(SSL *, BIO *, BIO *);
 extern int     (*x_SSL_set_ex_data)(SSL *, int, void *);
 extern int     (*x_SSL_shutdown)(SSL *);
 extern int     (*x_SSL_write)(SSL *, const void *, int);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 extern SSL_METHOD *(*x_SSLv23_server_method)(void);
+#else
+extern SSL_METHOD *(*x_TLS_server_method)(void);
+#endif
 extern X509 *  (*x_d2i_X509)(X509 **px, const unsigned char **in, int len);
 extern void    (*x_X509_free)(X509 *a);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 extern void    (*x_sk_zero)(void *st);
+#endif
 extern void   *(*x_SSL_COMP_get_compression_methods)(void);
 
 #define BIO_ctrl                     x_BIO_ctrl
@@ -146,6 +169,9 @@ extern void   *(*x_SSL_COMP_get_compression_methods)(v
 #define SSL_CTX_new                  x_SSL_CTX_new
 #define SSL_CTX_set_cipher_list      x_SSL_CTX_set_cipher_list
 #define SSL_CTX_set_info_callback    x_SSL_CTX_set_info_callback
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#define SSL_CTX_set_options          x_SSL_CTX_set_options
+#endif
 #define SSL_CTX_use_PrivateKey_file  x_SSL_CTX_use_PrivateKey_file
 #define SSL_CTX_use_PrivateKey_ASN1  x_SSL_CTX_use_PrivateKey_ASN1
 #define SSL_CTX_use_certificate_file x_SSL_CTX_use_certificate_file
@@ -157,7 +183,9 @@ extern void   *(*x_SSL_COMP_get_compression_methods)(v
 #define SSL_get_rbio                 x_SSL_get_rbio
 #define SSL_get_servername           x_SSL_get_servername
 #define SSL_get_wbio                 x_SSL_get_wbio
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 #define SSL_library_init             x_SSL_library_init
+#endif
 #define SSL_new                      x_SSL_new
 #define SSL_read                     x_SSL_read
 #define SSL_set_SSL_CTX              x_SSL_set_SSL_CTX
@@ -166,10 +194,16 @@ extern void   *(*x_SSL_COMP_get_compression_methods)(v
 #define SSL_set_ex_data              x_SSL_set_ex_data
 #define SSL_shutdown                 x_SSL_shutdown
 #define SSL_write                    x_SSL_write
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 #define SSLv23_server_method         x_SSLv23_server_method
+#else
+#define TLS_server_method            x_TLS_server_method
+#endif
 #define d2i_X509                     x_d2i_X509
 #define X509_free                    x_X509_free
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 #define sk_zero                      x_sk_zero
+#endif
 #define SSL_COMP_get_compression_methods    x_SSL_COMP_get_compression_methods
 
 #undef  BIO_set_buffer_read_data
