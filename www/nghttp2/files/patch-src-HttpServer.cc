--- src/HttpServer.cc.orig	2018-02-17 11:15:19 UTC
+++ src/HttpServer.cc
@@ -888,7 +888,9 @@ int Http2Handler::verify_npn_result() {
   const unsigned char *next_proto = nullptr;
   unsigned int next_proto_len;
   // Check the negotiated protocol in NPN or ALPN
+#ifndef OPENSSL_NO_NEXTPROTONEG
   SSL_get0_next_proto_negotiated(ssl_, &next_proto, &next_proto_len);
+#endif
   for (int i = 0; i < 2; ++i) {
     if (next_proto) {
       auto proto = StringRef{next_proto, next_proto_len};
@@ -2205,7 +2207,9 @@ int HttpServer::run() {
 
     next_proto = util::get_default_alpn();
 
+#ifndef OPENSSL_NO_NEXTPROTONEG
     SSL_CTX_set_next_protos_advertised_cb(ssl_ctx, next_proto_cb, &next_proto);
+#endif
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
     // ALPN selection callback
     SSL_CTX_set_alpn_select_cb(ssl_ctx, alpn_select_proto_cb, this);
