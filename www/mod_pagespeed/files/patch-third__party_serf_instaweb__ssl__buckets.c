--- third_party/serf/instaweb_ssl_buckets.c.orig	2017-06-08 22:22:39 UTC
+++ third_party/serf/instaweb_ssl_buckets.c
@@ -253,7 +253,11 @@ apps_ssl_info_callback(const SSL *s, int
 /* Returns the amount read. */
 static int bio_bucket_read(BIO *bio, char *in, int inlen)
 {
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     serf_ssl_context_t *ctx = bio->ptr;
+#else
+    serf_ssl_context_t *ctx = BIO_get_data(bio);
+#endif
     const char *data;
     apr_status_t status;
     apr_size_t len;
@@ -297,7 +301,11 @@ static int bio_bucket_read(BIO *bio, cha
 /* Returns the amount written. */
 static int bio_bucket_write(BIO *bio, const char *in, int inl)
 {
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     serf_ssl_context_t *ctx = bio->ptr;
+#else
+    serf_ssl_context_t *ctx = BIO_get_data(bio);
+#endif
     serf_bucket_t *tmp;
 
     serf__log(SSL_VERBOSE, __FILE__, "bio_bucket_write called for %d bytes\n",
@@ -325,7 +333,11 @@ static int bio_bucket_write(BIO *bio, co
 /* Returns the amount read. */
 static int bio_file_read(BIO *bio, char *in, int inlen)
 {
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     apr_file_t *file = bio->ptr;
+#else
+    apr_file_t *file = BIO_get_data(bio);
+#endif
     apr_status_t status;
     apr_size_t len;
 
@@ -350,7 +362,11 @@ static int bio_file_read(BIO *bio, char 
 /* Returns the amount written. */
 static int bio_file_write(BIO *bio, const char *in, int inl)
 {
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     apr_file_t *file = bio->ptr;
+#else
+    apr_file_t *file = BIO_get_data(bio);
+#endif
     apr_size_t nbytes;
 
     BIO_clear_retry_flags(bio);
@@ -368,10 +384,16 @@ static int bio_file_gets(BIO *bio, char 
 
 static int bio_bucket_create(BIO *bio)
 {
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     bio->shutdown = 1;
     bio->init = 1;
     bio->num = -1;
     bio->ptr = NULL;
+#else
+    BIO_set_shutdown(bio, 1);
+    BIO_set_init(bio, 1);
+    BIO_set_data(bio, NULL);
+#endif
 
     return 1;
 }
@@ -405,6 +427,7 @@ static long bio_bucket_ctrl(BIO *bio, in
     return ret;
 }
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 static BIO_METHOD bio_bucket_method = {
     BIO_TYPE_MEM,
     "Serf SSL encryption and decryption buckets",
@@ -434,6 +457,11 @@ static BIO_METHOD bio_file_method = {
     NULL /* sslc does not have the callback_ctrl field */
 #endif
 };
+#else
+static BIO_METHOD *bio_bucket_method = NULL;
+static BIO_METHOD *bio_file_method = NULL;
+#endif
+
 
 typedef enum san_copy_t {
     EscapeNulAndCopy = 0,
@@ -1088,7 +1116,9 @@ static void init_ssl_libraries(void)
         }
 #endif
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
         CRYPTO_malloc_init();
+#endif
         ERR_load_crypto_strings();
         SSL_load_error_strings();
         SSL_library_init();
@@ -1172,8 +1202,22 @@ static int ssl_need_client_cert(SSL *ssl
             continue;
         }
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
         bio = BIO_new(&bio_file_method);
         bio->ptr = cert_file;
+#else
+        if (bio_file_method == NULL) {
+            bio_file_method = BIO_meth_new(BIO_TYPE_FILE, "Wrapper around APR file structures");
+            BIO_meth_set_write(bio_file_method, bio_file_write);
+            BIO_meth_set_read(bio_file_method, bio_file_read);
+            BIO_meth_set_gets(bio_file_method, bio_file_gets);
+            BIO_meth_set_ctrl(bio_file_method, bio_bucket_ctrl);
+            BIO_meth_set_create(bio_file_method, bio_bucket_create);
+            BIO_meth_set_destroy(bio_file_method, bio_bucket_destroy);
+        }
+        bio = BIO_new(bio_file_method);
+        BIO_set_data(bio, cert_file);
+#endif
 
         ctx->cert_path = cert_path;
         p12 = d2i_PKCS12_bio(bio, NULL);
@@ -1351,8 +1395,21 @@ static serf_ssl_context_t *ssl_init_cont
     disable_compression(ssl_ctx);
 
     ssl_ctx->ssl = SSL_new(ssl_ctx->ctx);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     ssl_ctx->bio = BIO_new(&bio_bucket_method);
     ssl_ctx->bio->ptr = ssl_ctx;
+#else
+    if (bio_bucket_method == NULL) {
+        bio_bucket_method = BIO_meth_new(BIO_TYPE_MEM, "Serf SSL encryption and decryption buckets");
+        BIO_meth_set_write(bio_bucket_method, bio_bucket_write);
+        BIO_meth_set_read(bio_bucket_method, bio_bucket_read);
+        BIO_meth_set_ctrl(bio_bucket_method, bio_bucket_ctrl);
+        BIO_meth_set_create(bio_bucket_method, bio_bucket_create);
+        BIO_meth_set_destroy(bio_bucket_method, bio_bucket_destroy);
+    }
+    ssl_ctx->bio = BIO_new(bio_bucket_method);
+    BIO_set_data(ssl_ctx->bio, ssl_ctx);
+#endif
 
     SSL_set_bio(ssl_ctx->ssl, ssl_ctx->bio, ssl_ctx->bio);
 
@@ -1697,11 +1754,15 @@ int serf_ssl_cert_depth(const serf_ssl_c
 int serf_ssl_check_host(const serf_ssl_certificate_t *cert,
                         const char* hostname)
 {
+#if TSI_OPENSSL_ALPN_SUPPORT == 0
+  return (-1);
+#else
   return X509_check_host(cert->ssl_cert,
                          hostname,
                          strlen(hostname),
                          0 /* we don't need to set any flags */,
                          NULL /* we don't need the SAN or CN extracted*/);
+#endif
 }
 
 apr_hash_t *serf_ssl_cert_issuer(
