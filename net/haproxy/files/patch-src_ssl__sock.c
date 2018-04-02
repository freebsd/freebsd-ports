--- src/ssl_sock.c.orig	2018-01-02 14:14:08 UTC
+++ src/ssl_sock.c
@@ -794,8 +794,11 @@ static int ssl_sock_load_ocsp(SSL_CTX *c
 		ocsp = NULL;
 
 #ifndef SSL_CTX_get_tlsext_status_cb
+#ifndef SSL_CTRL_GET_TLSEXT_STATUS_REQ_CB
+#define SSL_CTRL_GET_TLSEXT_STATUS_REQ_CB 128
+#endif
 # define SSL_CTX_get_tlsext_status_cb(ctx, cb) \
-	*cb = (void (*) (void))ctx->tlsext_status_cb;
+	*cb = SSL_CTX_ctrl(ctx,SSL_CTRL_GET_TLSEXT_STATUS_REQ_CB,0, (void (**)(void))cb)
 #endif
 	SSL_CTX_get_tlsext_status_cb(ctx, &callback);
 
@@ -823,7 +826,10 @@ static int ssl_sock_load_ocsp(SSL_CTX *c
 		int key_type;
 		EVP_PKEY *pkey;
 
-#ifdef SSL_CTX_get_tlsext_status_arg
+#if defined(SSL_CTX_get_tlsext_status_arg) || defined(LIBRESSL_VERSION_NUMBER)
+#ifndef SSL_CTRL_GET_TLSEXT_STATUS_REQ_CB_ARG
+#define SSL_CTRL_GET_TLSEXT_STATUS_REQ_CB_ARG 129
+#endif
 		SSL_CTX_ctrl(ctx, SSL_CTRL_GET_TLSEXT_STATUS_REQ_CB_ARG, 0, &cb_arg);
 #else
 		cb_arg = ctx->tlsext_status_arg;
@@ -1142,7 +1148,7 @@ void ssl_sock_msgcbk(int write_p, int ve
 #endif
 }
 
-#ifdef OPENSSL_NPN_NEGOTIATED
+#if defined(OPENSSL_NPN_NEGOTIATED) && !defined(OPENSSL_NO_NEXTPROTONEG)
 /* This callback is used so that the server advertises the list of
  * negociable protocols for NPN.
  */
@@ -2870,7 +2876,7 @@ int ssl_sock_prepare_ctx(struct bind_con
 	SSL_CTX_set_msg_callback(ctx, ssl_sock_msgcbk);
 #endif
 
-#ifdef OPENSSL_NPN_NEGOTIATED
+#if defined(OPENSSL_NPN_NEGOTIATED) && !defined(OPENSSL_NO_NEXTPROTONEG)
 	if (bind_conf->npn_str)
 		SSL_CTX_set_next_protos_advertised_cb(ctx, ssl_sock_advertise_npn_protos, bind_conf);
 #endif
@@ -3539,7 +3545,7 @@ int ssl_sock_handshake(struct connection
 					OSSL_HANDSHAKE_STATE state = SSL_get_state((SSL *)conn->xprt_ctx);
 					empty_handshake = state == TLS_ST_BEFORE;
 #else
-					empty_handshake = !((SSL *)conn->xprt_ctx)->packet_length;
+					empty_handshake = SSL_state((SSL *)conn->xprt_ctx) == SSL_ST_BEFORE;
 #endif
 
 					if (empty_handshake) {
@@ -3617,7 +3623,7 @@ int ssl_sock_handshake(struct connection
 			state = SSL_get_state((SSL *)conn->xprt_ctx);
 			empty_handshake = state == TLS_ST_BEFORE;
 #else
-			empty_handshake = !((SSL *)conn->xprt_ctx)->packet_length;
+			empty_handshake = SSL_state((SSL *)conn->xprt_ctx) == SSL_ST_BEFORE;
 #endif
 			if (empty_handshake) {
 				if (!errno) {
@@ -4886,7 +4892,7 @@ smp_fetch_ssl_fc_use_keysize(const struc
 	return 1;
 }
 
-#ifdef OPENSSL_NPN_NEGOTIATED
+#if defined(OPENSSL_NPN_NEGOTIATED) && !defined(OPENSSL_NO_NEXTPROTONEG)
 static int
 smp_fetch_ssl_fc_npn(const struct arg *args, struct sample *smp, const char *kw, void *private)
 {
@@ -5413,7 +5419,7 @@ static int bind_parse_no_tlsv12(char **a
 /* parse the "npn" bind keyword */
 static int bind_parse_npn(char **args, int cur_arg, struct proxy *px, struct bind_conf *conf, char **err)
 {
-#ifdef OPENSSL_NPN_NEGOTIATED
+#if defined(OPENSSL_NPN_NEGOTIATED) && !defined(OPENSSL_NO_NEXTPROTONEG)
 	char *p1, *p2;
 
 	if (!*args[cur_arg + 1]) {
@@ -6313,7 +6319,7 @@ static struct sample_fetch_kw_list sampl
 	{ "ssl_fc_has_crt",         smp_fetch_ssl_fc_has_crt,     0,                   NULL,    SMP_T_BOOL, SMP_USE_L5CLI },
 	{ "ssl_fc_has_sni",         smp_fetch_ssl_fc_has_sni,     0,                   NULL,    SMP_T_BOOL, SMP_USE_L5CLI },
 	{ "ssl_fc_is_resumed",      smp_fetch_ssl_fc_is_resumed,  0,                   NULL,    SMP_T_BOOL, SMP_USE_L5CLI },
-#ifdef OPENSSL_NPN_NEGOTIATED
+#if defined(OPENSSL_NPN_NEGOTIATED) && !defined(OPENSSL_NO_NEXTPROTONEG)
 	{ "ssl_fc_npn",             smp_fetch_ssl_fc_npn,         0,                   NULL,    SMP_T_STR,  SMP_USE_L5CLI },
 #endif
 #ifdef TLSEXT_TYPE_application_layer_protocol_negotiation
