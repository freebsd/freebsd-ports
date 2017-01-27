Obtained from:	https://github.com/nghttp2/nghttp2/commit/16be89f9ccba4d37e34ef03f20009a9845efeb99

--- src/shrpx_ssl.cc.orig	2017-01-25 11:30:16 UTC
+++ src/shrpx_ssl.cc
@@ -525,6 +525,7 @@ int sct_parse_cb(SSL *ssl, unsigned int 
 } // namespace
 #endif // !LIBRESSL_IN_USE && OPENSSL_VERSION_NUMBER >= 0x10002000L
 
+#if !LIBRESSL_IN_USE
 namespace {
 unsigned int psk_server_cb(SSL *ssl, const char *identity, unsigned char *psk,
                            unsigned int max_psk_len) {
@@ -548,7 +549,9 @@ unsigned int psk_server_cb(SSL *ssl, con
   return static_cast<unsigned int>(secret.size());
 }
 } // namespace
+#endif // !LIBRESSL_IN_USE
 
+#if !LIBRESSL_IN_USE
 namespace {
 unsigned int psk_client_cb(SSL *ssl, const char *hint, char *identity_out,
                            unsigned int max_identity_len, unsigned char *psk,
@@ -581,6 +584,7 @@ unsigned int psk_client_cb(SSL *ssl, con
   return (unsigned int)secret.size();
 }
 } // namespace
+#endif // !LIBRESSL_IN_USE
 
 struct TLSProtocol {
   StringRef name;
@@ -784,7 +788,9 @@ SSL_CTX *create_ssl_context(const char *
   }
 #endif // !LIBRESSL_IN_USE && OPENSSL_VERSION_NUMBER >= 0x10002000L
 
+#if !LIBRESSL_IN_USE
   SSL_CTX_set_psk_server_callback(ssl_ctx, psk_server_cb);
+#endif // !LIBRESSL_IN_USE
 
   auto tls_ctx_data = new TLSContextData();
   tls_ctx_data->cert_file = cert_file;
@@ -919,7 +925,9 @@ SSL_CTX *create_ssl_client_context(
 #endif // HAVE_NEVERBLEED
   }
 
+#if !LIBRESSL_IN_USE
   SSL_CTX_set_psk_client_callback(ssl_ctx, psk_client_cb);
+#endif // !LIBRESSL_IN_USE
 
   // NPN selection callback.  This is required to set SSL_CTX because
   // OpenSSL does not offer SSL_set_next_proto_select_cb.
