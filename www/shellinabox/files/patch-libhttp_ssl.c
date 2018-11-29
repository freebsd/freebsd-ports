--- libhttp/ssl.c.orig	2016-11-09 19:40:33 UTC
+++ libhttp/ssl.c
@@ -117,6 +117,9 @@ SSL_CTX *     (*SSL_CTX_new)(SSL_METHOD *);
 int           (*SSL_CTX_set_cipher_list)(SSL_CTX *, const char *);
 void          (*SSL_CTX_set_info_callback)(SSL_CTX *,
                                            void (*)(const SSL *, int, int));
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+unsigned long (*SSL_CTX_set_options)(SSL_CTX *, unsigned long);
+#endif
 int           (*SSL_CTX_use_PrivateKey_file)(SSL_CTX *, const char *, int);
 int           (*SSL_CTX_use_PrivateKey_ASN1)(int, SSL_CTX *,
                                              const unsigned char *, long);
@@ -130,7 +133,9 @@ void *        (*SSL_get_ex_data)(const SSL *, int);
 BIO *         (*SSL_get_rbio)(const SSL *);
 const char *  (*SSL_get_servername)(const SSL *, int);
 BIO *         (*SSL_get_wbio)(const SSL *);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 int           (*SSL_library_init)(void);
+#endif
 SSL *         (*SSL_new)(SSL_CTX *);
 int           (*SSL_read)(SSL *, void *, int);
 SSL_CTX *     (*SSL_set_SSL_CTX)(SSL *, SSL_CTX *);
@@ -139,10 +144,16 @@ void          (*SSL_set_bio)(SSL *, BIO *, BIO *);
 int           (*SSL_set_ex_data)(SSL *, int, void *);
 int           (*SSL_shutdown)(SSL *);
 int           (*SSL_write)(SSL *, const void *, int);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 SSL_METHOD *  (*SSLv23_server_method)(void);
+#else
+SSL_METHOD *  (*TLS_server_method)(void);
+#endif
 X509 *        (*d2i_X509)(X509 **px, const unsigned char **in, int len);
 void          (*X509_free)(X509 *a);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 void          (*x_sk_zero)(void *st);
+#endif
 void *        (*x_SSL_COMP_get_compression_methods)(void);
 #endif
 
@@ -208,7 +219,7 @@ static int maybeLoadCrypto(void) {
   // The feature is currently disabled.
   const char* path_libcrypto = NULL; // getenv ("SHELLINABOX_LIBCRYPTO_SO");
   if (path_libcrypto == NULL)
-    path_libcrypto = "libcrypto.so";
+    path_libcrypto = DEFAULT_LIBCRYPTO_SO;
 
   if (!crypto++) {
 #ifdef RTLD_NOLOAD
@@ -267,8 +278,8 @@ static void loadSSL(void) {
   // The feature is currently disabled.
   const char* path_libssl = NULL; // = getenv ("SHELLINABOX_LIBSSL_SO");
   if (path_libssl == NULL)
-    path_libssl = "libssl.so";
-  check(!SSL_library_init);
+    path_libssl = DEFAULT_LIBSSL_SO;
+  check(!SSL_CTX_new);
   struct {
     union {
       void *avoid_gcc_warning_about_type_punning;
@@ -299,6 +310,9 @@ static void loadSSL(void) {
     { { &SSL_CTX_new },                 "SSL_CTX_new" },
     { { &SSL_CTX_set_cipher_list },     "SSL_CTX_set_cipher_list" },
     { { &SSL_CTX_set_info_callback },   "SSL_CTX_set_info_callback" },
+#if OPENSSL_VERSION_NUMBER > 0x10100000L
+    { { &SSL_CTX_set_options },         "SSL_CTX_set_options" },
+#endif
     { { &SSL_CTX_use_PrivateKey_file }, "SSL_CTX_use_PrivateKey_file" },
     { { &SSL_CTX_use_PrivateKey_ASN1 }, "SSL_CTX_use_PrivateKey_ASN1" },
     { { &SSL_CTX_use_certificate_file },"SSL_CTX_use_certificate_file"},
@@ -312,7 +326,9 @@ static void loadSSL(void) {
     { { &SSL_get_servername },          "SSL_get_servername" },
 #endif
     { { &SSL_get_wbio },                "SSL_get_wbio" },
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     { { &SSL_library_init },            "SSL_library_init" },
+#endif
     { { &SSL_new },                     "SSL_new" },
     { { &SSL_read },                    "SSL_read" },
 #ifdef HAVE_TLSEXT
@@ -323,10 +339,16 @@ static void loadSSL(void) {
     { { &SSL_set_ex_data },             "SSL_set_ex_data" },
     { { &SSL_shutdown },                "SSL_shutdown" },
     { { &SSL_write },                   "SSL_write" },
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     { { &SSLv23_server_method },        "SSLv23_server_method" },
+#else
+    { { &TLS_server_method },           "TLS_server_method" },
+#endif
     { { &d2i_X509 },                    "d2i_X509" },
     { { &X509_free },                   "X509_free" },
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     { { &x_sk_zero },                   "sk_zero" }
+#endif
   };
   for (unsigned i = 0; i < sizeof(symbols)/sizeof(symbols[0]); i++) {
     if (!(*symbols[i].var = loadSymbol(path_libssl, symbols[i].fn))) {
@@ -343,7 +365,9 @@ static void loadSSL(void) {
   // ends
 
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
   SSL_library_init();
+#endif
   dcheck(!ERR_peek_error());
   debug("[ssl] Loaded SSL suppport...");
 }
@@ -351,8 +375,12 @@ static void loadSSL(void) {
 
 int serverSupportsSSL(void) {
 #if defined(HAVE_OPENSSL) && !defined(HAVE_DLOPEN)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
   return SSL_library_init();
 #else
+  return 1;
+#endif
+#else
 #if defined(HAVE_OPENSSL)
   // We want to call loadSSL() exactly once. For single-threaded applications,
   // this is straight-forward. For threaded applications, we need to call
@@ -372,8 +400,12 @@ int serverSupportsSSL(void) {
       loadSSL();
     }
   }
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
   return !!SSL_library_init;
 #else
+  return 1;
+#endif
+#else
   return 0;
 #endif
 #endif
@@ -623,7 +655,11 @@ static void sslInfoCallback(const SSL *sslHndl, int ty
 static SSL_CTX *sslMakeContext(void) {
 
   SSL_CTX *context;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
   check(context = SSL_CTX_new(SSLv23_server_method()));
+#else
+  check(context = SSL_CTX_new(TLS_server_method()));
+#endif
 
   long options  = SSL_OP_ALL;
   options      |= SSL_OP_NO_SSLv2;
@@ -641,6 +677,7 @@ static SSL_CTX *sslMakeContext(void) {
   // Set default SSL options.
   SSL_CTX_set_options(context, options);
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
   // Workaround for SSL_OP_NO_COMPRESSION with older OpenSSL versions.
 #ifdef HAVE_DLOPEN
   if (SSL_COMP_get_compression_methods) {
@@ -649,6 +686,7 @@ static SSL_CTX *sslMakeContext(void) {
 #elif OPENSSL_VERSION_NUMBER >= 0x00908000L
   sk_SSL_COMP_zero(SSL_COMP_get_compression_methods());
 #endif
+#endif
 
   // For Perfect Forward Secrecy (PFS) support we need to enable some additional
   // SSL options, provide eliptic curve key object for handshake and add chipers
@@ -657,21 +695,39 @@ static SSL_CTX *sslMakeContext(void) {
   SSL_CTX_set_options(context, SSL_OP_SINGLE_ECDH_USE);
   SSL_CTX_set_options(context, SSL_OP_CIPHER_SERVER_PREFERENCE);
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L /* openssl 1.1 does this automatically */
   EC_KEY *ecKey;
   check(ecKey   = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1));
   SSL_CTX_set_tmp_ecdh(context, ecKey);
   EC_KEY_free(ecKey);
+#endif
 
   debug("[ssl] Support for PFS enabled...");
 #endif
 
   check(SSL_CTX_set_cipher_list(context,
+#ifdef SHELLINABOX_USE_CHACHA_FIRST
+    "ECDHE-ECDSA-CHACHA20-POLY1305:"
+    "ECDHE-RSA-CHACHA20-POLY1305:"
+    "ECDHE-ECDSA-AES256-GCM-SHA384:"
     "ECDHE-RSA-AES256-GCM-SHA384:"
+#else
+    "ECDHE-ECDSA-AES256-GCM-SHA384:"
+    "ECDHE-RSA-AES256-GCM-SHA384:"
+    "ECDHE-ECDSA-CHACHA20-POLY1305:"
+    "ECDHE-RSA-CHACHA20-POLY1305:"
+#endif
+    "ECDHE-ECDSA-AES128-GCM-SHA256:"
     "ECDHE-RSA-AES128-GCM-SHA256:"
+    "ECDHE-ECDSA-AES256-SHA384:"
     "ECDHE-RSA-AES256-SHA384:"
+    "ECDHE-ECDSA-AES128-SHA256:"
     "ECDHE-RSA-AES128-SHA256:"
+    "ECDHE-ECDSA-AES256-SHA:"
     "ECDHE-RSA-AES256-SHA:"
+    "ECDHE-ECDSA-AES128-SHA:"
     "ECDHE-RSA-AES128-SHA:"
+    "ECDHE-ECDSA-DES-CBC3-SHA:"
     "ECDHE-RSA-DES-CBC3-SHA:"
     "HIGH:MEDIUM:!RC4:!aNULL:!MD5"));
 
