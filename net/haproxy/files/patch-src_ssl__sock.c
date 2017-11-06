--- src/ssl_sock.c.orig	2017-07-07 09:49:34 UTC
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
