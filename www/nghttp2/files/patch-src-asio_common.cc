--- src/asio_common.cc.orig	2018-02-02 12:19:16 UTC
+++ src/asio_common.cc
@@ -177,7 +177,9 @@ bool tls_h2_negotiated(ssl_socket &socke
   const unsigned char *next_proto = nullptr;
   unsigned int next_proto_len = 0;
 
+#ifndef OPENSSL_NO_NEXTPROTONEG
   SSL_get0_next_proto_negotiated(ssl, &next_proto, &next_proto_len);
+#endif
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
   if (next_proto == nullptr) {
     SSL_get0_alpn_selected(ssl, &next_proto, &next_proto_len);
