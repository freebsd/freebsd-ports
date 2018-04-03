--- src/shrpx_tls.cc.orig	2018-03-25 12:28:55 UTC
+++ src/shrpx_tls.cc
@@ -360,7 +360,7 @@ int tls_session_new_cb(SSL *ssl, SSL_SES
 
 namespace {
 SSL_SESSION *tls_session_get_cb(SSL *ssl,
-#if OPENSSL_1_1_API
+#if OPENSSL_1_1_API && !LIBRESSL_1_1_API
                                 const unsigned char *id,
 #else  // !OPENSSL_1_1_API
                                 unsigned char *id,
@@ -563,7 +563,7 @@ int alpn_select_proto_cb(SSL *ssl, const
 } // namespace
 #endif // OPENSSL_VERSION_NUMBER >= 0x10002000L
 
-#if !LIBRESSL_IN_USE && OPENSSL_VERSION_NUMBER >= 0x10002000L
+#if !LIBRESSL_1_0_API && OPENSSL_VERSION_NUMBER >= 0x10002000L
 
 #ifndef TLSEXT_TYPE_signed_certificate_timestamp
 #define TLSEXT_TYPE_signed_certificate_timestamp 18
@@ -653,9 +653,9 @@ int legacy_sct_parse_cb(SSL *ssl, unsign
 } // namespace
 
 #endif // !OPENSSL_1_1_1_API
-#endif // !LIBRESSL_IN_USE && OPENSSL_VERSION_NUMBER >= 0x10002000L
+#endif // !LIBRESSL_1_0_API && OPENSSL_VERSION_NUMBER >= 0x10002000L
 
-#if !LIBRESSL_IN_USE
+#ifndef OPENSSL_NO_PSK
 namespace {
 unsigned int psk_server_cb(SSL *ssl, const char *identity, unsigned char *psk,
                            unsigned int max_psk_len) {
@@ -679,9 +679,9 @@ unsigned int psk_server_cb(SSL *ssl, con
   return static_cast<unsigned int>(secret.size());
 }
 } // namespace
-#endif // !LIBRESSL_IN_USE
+#endif // !OPENSSL_NO_PSK
 
-#if !LIBRESSL_IN_USE
+#ifndef OPENSSL_NO_PSK
 namespace {
 unsigned int psk_client_cb(SSL *ssl, const char *hint, char *identity_out,
                            unsigned int max_identity_len, unsigned char *psk,
@@ -714,7 +714,7 @@ unsigned int psk_client_cb(SSL *ssl, con
   return static_cast<unsigned int>(secret.size());
 }
 } // namespace
-#endif // !LIBRESSL_IN_USE
+#endif // !OPENSSL_NO_PSK
 
 struct TLSProtocol {
   StringRef name;
@@ -792,7 +792,7 @@ SSL_CTX *create_ssl_context(const char *
   }
 
 #ifndef OPENSSL_NO_EC
-#if !LIBRESSL_IN_USE && OPENSSL_VERSION_NUMBER >= 0x10002000L
+#if !LIBRESSL_1_0_API && OPENSSL_VERSION_NUMBER >= 0x10002000L
   if (SSL_CTX_set1_curves_list(ssl_ctx, tlsconf.ecdh_curves.c_str()) != 1) {
     LOG(FATAL) << "SSL_CTX_set1_curves_list " << tlsconf.ecdh_curves
                << " failed";
@@ -803,7 +803,7 @@ SSL_CTX *create_ssl_context(const char *
   // function was deprecated in OpenSSL 1.1.0 and BoringSSL.
   SSL_CTX_set_ecdh_auto(ssl_ctx, 1);
 #endif // !defined(OPENSSL_IS_BORINGSSL) && !OPENSSL_1_1_API
-#else  // LIBRESSL_IN_USE || OPENSSL_VERSION_NUBMER < 0x10002000L
+#else  // LIBRESSL_1_0_API || OPENSSL_VERSION_NUBMER < 0x10002000L
   // Use P-256, which is sufficiently secure at the time of this
   // writing.
   auto ecdh = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);
@@ -814,7 +814,7 @@ SSL_CTX *create_ssl_context(const char *
   }
   SSL_CTX_set_tmp_ecdh(ssl_ctx, ecdh);
   EC_KEY_free(ecdh);
-#endif // LIBRESSL_IN_USE || OPENSSL_VERSION_NUBMER < 0x10002000L
+#endif // LIBRESSL_1_0_API || OPENSSL_VERSION_NUBMER < 0x10002000L
 #endif // OPENSSL_NO_EC
 
   if (!tlsconf.dh_param_file.empty()) {
@@ -931,7 +931,7 @@ SSL_CTX *create_ssl_context(const char *
   SSL_CTX_set_alpn_select_cb(ssl_ctx, alpn_select_proto_cb, nullptr);
 #endif // OPENSSL_VERSION_NUMBER >= 0x10002000L
 
-#if !LIBRESSL_IN_USE && OPENSSL_VERSION_NUMBER >= 0x10002000L
+#if !LIBRESSL_1_0_API && !LIBRESSL_1_1_API && OPENSSL_VERSION_NUMBER >= 0x10002000L
   // SSL_extension_supported(TLSEXT_TYPE_signed_certificate_timestamp)
   // returns 1, which means OpenSSL internally handles it.  But
   // OpenSSL handles signed_certificate_timestamp extension specially,
@@ -962,11 +962,11 @@ SSL_CTX *create_ssl_context(const char *
     }
 #endif // !OPENSSL_1_1_1_API
   }
-#endif // !LIBRESSL_IN_USE && OPENSSL_VERSION_NUMBER >= 0x10002000L
+#endif // !LIBRESSL_1_0_API && OPENSSL_VERSION_NUMBER >= 0x10002000L
 
-#if !LIBRESSL_IN_USE
+#ifndef OPENSSL_NO_PSK
   SSL_CTX_set_psk_server_callback(ssl_ctx, psk_server_cb);
-#endif // !LIBRESSL_IN_USE
+#endif // !OPENSSL_NO_PSK
 
   auto tls_ctx_data = new TLSContextData();
   tls_ctx_data->cert_file = cert_file;
@@ -1114,9 +1114,9 @@ SSL_CTX *create_ssl_client_context(
 #endif // HAVE_NEVERBLEED
   }
 
-#if !LIBRESSL_IN_USE
+#ifndef OPENSSL_NO_PSK
   SSL_CTX_set_psk_client_callback(ssl_ctx, psk_client_cb);
-#endif // !LIBRESSL_IN_USE
+#endif // !OPENSSL_NO_PSK
 
   // NPN selection callback.  This is required to set SSL_CTX because
   // OpenSSL does not offer SSL_set_next_proto_select_cb.
@@ -1553,15 +1553,15 @@ int cert_lookup_tree_add_ssl_ctx(
     SSL_CTX *ssl_ctx) {
   std::array<uint8_t, NI_MAXHOST> buf;
 
-#if !defined(LIBRESSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x10002000L
+#if !defined(LIBRESSL_1_0_API) && OPENSSL_VERSION_NUMBER >= 0x10002000L
   auto cert = SSL_CTX_get0_certificate(ssl_ctx);
-#else  // defined(LIBRESSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER <
+#else  // defined(LIBRESSL_1_0_API) || OPENSSL_VERSION_NUMBER <
   // 0x10002000L
   auto tls_ctx_data =
       static_cast<TLSContextData *>(SSL_CTX_get_app_data(ssl_ctx));
   auto cert = load_certificate(tls_ctx_data->cert_file);
   auto cert_deleter = defer(X509_free, cert);
-#endif // defined(LIBRESSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER <
+#endif // defined(LIBRESSL_1_0_API) || OPENSSL_VERSION_NUMBER <
        // 0x10002000L
 
   auto altnames = static_cast<GENERAL_NAMES *>(
@@ -1977,7 +1977,7 @@ StringRef get_x509_issuer_name(BlockAllo
 #endif /* !WORDS_BIGENDIAN */
 
 StringRef get_x509_serial(BlockAllocator &balloc, X509 *x) {
-#if OPENSSL_1_1_API
+#if OPENSSL_1_1_API && !LIBRESSL_1_1_API
   auto sn = X509_get0_serialNumber(x);
   uint64_t r;
   if (ASN1_INTEGER_get_uint64(&r, sn) != 1) {
