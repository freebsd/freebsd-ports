--- src/shrpx_client_handler.cc.orig	2018-02-02 12:19:16 UTC
+++ src/shrpx_client_handler.cc
@@ -549,7 +549,9 @@ int ClientHandler::validate_next_proto()
   // First set callback for catch all cases
   on_read_ = &ClientHandler::upstream_read;
 
+#ifndef OPENSSL_NO_NEXTPROTONEG
   SSL_get0_next_proto_negotiated(conn_.tls.ssl, &next_proto, &next_proto_len);
+#endif
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
   if (next_proto == nullptr) {
     SSL_get0_alpn_selected(conn_.tls.ssl, &next_proto, &next_proto_len);
