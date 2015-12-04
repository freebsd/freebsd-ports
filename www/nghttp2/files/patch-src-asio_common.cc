--- src/asio_common.cc.orig	2015-11-26 13:27:10 UTC
+++ src/asio_common.cc
@@ -177,9 +177,11 @@ bool tls_h2_negotiated(ssl_socket &socke
   unsigned int next_proto_len = 0;
 
   SSL_get0_next_proto_negotiated(ssl, &next_proto, &next_proto_len);
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L
   if (next_proto == nullptr) {
     SSL_get0_alpn_selected(ssl, &next_proto, &next_proto_len);
   }
+#endif // OPENSSL_VERSION_NUMBER >= 0x10002000L
 
   if (next_proto == nullptr) {
     return false;
