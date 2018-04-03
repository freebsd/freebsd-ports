--- examples/libevent-client.c.orig	2018-02-02 12:19:16 UTC
+++ examples/libevent-client.c
@@ -335,7 +335,9 @@ static SSL_CTX *create_ssl_ctx(void) {
                       SSL_OP_ALL | SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3 |
                           SSL_OP_NO_COMPRESSION |
                           SSL_OP_NO_SESSION_RESUMPTION_ON_RENEGOTIATION);
+#ifndef OPENSSL_NO_NEXTPROTONEG
   SSL_CTX_set_next_proto_select_cb(ssl_ctx, select_next_proto_cb, NULL);
+#endif
 
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
   SSL_CTX_set_alpn_protos(ssl_ctx, (const unsigned char *)"\x02h2", 3);
@@ -504,7 +506,9 @@ static void eventcb(struct bufferevent *
 
     ssl = bufferevent_openssl_get_ssl(session_data->bev);
 
+#ifndef OPENSSL_NO_NEXTPROTONEG
     SSL_get0_next_proto_negotiated(ssl, &alpn, &alpnlen);
+#endif
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
     if (alpn == NULL) {
       SSL_get0_alpn_selected(ssl, &alpn, &alpnlen);
