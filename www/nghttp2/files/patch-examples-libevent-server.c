--- examples/libevent-server.c.orig	2018-02-02 12:19:16 UTC
+++ examples/libevent-server.c
@@ -172,7 +172,9 @@ static SSL_CTX *create_ssl_ctx(const cha
          NGHTTP2_PROTO_VERSION_ID_LEN);
   next_proto_list_len = 1 + NGHTTP2_PROTO_VERSION_ID_LEN;
 
+#ifndef OPENSSL_NO_NEXTPROTONEG
   SSL_CTX_set_next_protos_advertised_cb(ssl_ctx, next_proto_cb, NULL);
+#endif
 
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
   SSL_CTX_set_alpn_select_cb(ssl_ctx, alpn_select_proto_cb, NULL);
@@ -690,7 +692,9 @@ static void eventcb(struct bufferevent *
 
     ssl = bufferevent_openssl_get_ssl(session_data->bev);
 
+#ifndef OPENSSL_NO_NEXTPROTONEG
     SSL_get0_next_proto_negotiated(ssl, &alpn, &alpnlen);
+#endif
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
     if (alpn == NULL) {
       SSL_get0_alpn_selected(ssl, &alpn, &alpnlen);
