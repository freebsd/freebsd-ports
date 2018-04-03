--- src/h2load.cc.orig	2018-02-02 12:19:16 UTC
+++ src/h2load.cc
@@ -857,7 +857,9 @@ int Client::connection_made() {
     const unsigned char *next_proto = nullptr;
     unsigned int next_proto_len;
 
+#ifndef OPENSSL_NO_NEXTPROTONEG
     SSL_get0_next_proto_negotiated(ssl, &next_proto, &next_proto_len);
+#endif
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
     if (next_proto == nullptr) {
       SSL_get0_alpn_selected(ssl, &next_proto, &next_proto_len);
@@ -2399,8 +2401,10 @@ int main(int argc, char **argv) {
     exit(EXIT_FAILURE);
   }
 
+#ifndef OPENSSL_NO_NEXTPROTONEG
   SSL_CTX_set_next_proto_select_cb(ssl_ctx, client_select_next_proto_cb,
                                    nullptr);
+#endif
 
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
   std::vector<unsigned char> proto_list;
