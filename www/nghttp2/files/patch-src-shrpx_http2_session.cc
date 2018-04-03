--- src/shrpx_http2_session.cc.orig	2018-02-02 12:19:16 UTC
+++ src/shrpx_http2_session.cc
@@ -1649,7 +1649,9 @@ int Http2Session::connection_made() {
     const unsigned char *next_proto = nullptr;
     unsigned int next_proto_len = 0;
 
+#ifndef OPENSSL_NO_NEXTPROTONEG
     SSL_get0_next_proto_negotiated(conn_.tls.ssl, &next_proto, &next_proto_len);
+#endif
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
     if (!next_proto) {
       SSL_get0_alpn_selected(conn_.tls.ssl, &next_proto, &next_proto_len);
