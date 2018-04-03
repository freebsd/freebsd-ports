--- src/shrpx_connection.cc.orig	2018-02-02 12:19:16 UTC
+++ src/shrpx_connection.cc
@@ -523,7 +523,9 @@ int Connection::check_http2_requirement(
   const unsigned char *next_proto = nullptr;
   unsigned int next_proto_len;
 
+#ifndef OPENSSL_NO_NEXTPROTONEG
   SSL_get0_next_proto_negotiated(tls.ssl, &next_proto, &next_proto_len);
+#endif
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
   if (next_proto == nullptr) {
     SSL_get0_alpn_selected(tls.ssl, &next_proto, &next_proto_len);
