--- src/ssl_sock.c.orig	2017-06-02 13:59:51 UTC
+++ src/ssl_sock.c
@@ -56,7 +56,7 @@
 #include <openssl/engine.h>
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if (OPENSSL_VERSION_NUMBER >= 0x1010000fL) && !defined(LIBRESSL_VERSION_NUMBER)
 #include <openssl/async.h>
 #endif
 
@@ -362,7 +362,7 @@ fail_get:
 }
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if (OPENSSL_VERSION_NUMBER >= 0x1010000fL) && !defined(LIBRESSL_VERSION_NUMBER)
 /*
  * openssl async fd handler
  */
@@ -1034,10 +1034,13 @@ static int ssl_sock_load_ocsp(SSL_CTX *c
 		ocsp = NULL;
 
 #ifndef SSL_CTX_get_tlsext_status_cb
-# define SSL_CTX_get_tlsext_status_cb(ctx, cb) \
-	*cb = (void (*) (void))ctx->tlsext_status_cb;
+#ifndef SSL_CTRL_GET_TLSEXT_STATUS_REQ_CB
+#define SSL_CTRL_GET_TLSEXT_STATUS_REQ_CB 128
 #endif
+	callback = SSL_CTX_ctrl(ctx, SSL_CTRL_GET_TLSEXT_STATUS_REQ_CB, 0, callback);
+#else
 	SSL_CTX_get_tlsext_status_cb(ctx, &callback);
+#endif
 
 	if (!callback) {
 		struct ocsp_cbk_arg *cb_arg = calloc(1, sizeof(*cb_arg));
@@ -1063,7 +1066,10 @@ static int ssl_sock_load_ocsp(SSL_CTX *c
 		int key_type;
 		EVP_PKEY *pkey;
 
-#ifdef SSL_CTX_get_tlsext_status_arg
+#if defined(SSL_CTX_get_tlsext_status_arg) || (LIBRESSL_VERSION_NUMBER >= 0x2050100fL)
+#ifndef SSL_CTRL_GET_TLSEXT_STATUS_REQ_CB_ARG
+#define SSL_CTRL_GET_TLSEXT_STATUS_REQ_CB_ARG 129
+#endif
 		SSL_CTX_ctrl(ctx, SSL_CTRL_GET_TLSEXT_STATUS_REQ_CB_ARG, 0, &cb_arg);
 #else
 		cb_arg = ctx->tlsext_status_arg;
@@ -3403,7 +3409,7 @@ int ssl_sock_load_cert_list_file(char *f
 #define SSL_MODE_SMALL_BUFFERS 0
 #endif
 
-#if (OPENSSL_VERSION_NUMBER < 0x1010000fL) && !defined(OPENSSL_IS_BORINGSSL)
+#if (OPENSSL_VERSION_NUMBER < 0x1010000fL) && !defined(OPENSSL_IS_BORINGSSL) || defined(LIBRESSL_VERSION_NUMBER)
 static void ssl_set_SSLv3_func(SSL_CTX *ctx, int is_server)
 {
 #if SSL_OP_NO_SSLv3
@@ -3560,7 +3566,7 @@ ssl_sock_initial_ctx(struct bind_conf *b
 		options &= ~SSL_OP_CIPHER_SERVER_PREFERENCE;
 	SSL_CTX_set_options(ctx, options);
 
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if (OPENSSL_VERSION_NUMBER >= 0x1010000fL) && !defined(LIBRESSL_VERSION_NUMBER)
 	if (global_ssl.async)
 		mode |= SSL_MODE_ASYNC;
 #endif
@@ -4010,7 +4016,7 @@ int ssl_sock_prepare_srv_ctx(struct serv
 		options |= SSL_OP_NO_TICKET;
 	SSL_CTX_set_options(ctx, options);
 
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if (OPENSSL_VERSION_NUMBER >= 0x1010000fL) && !defined(LIBRESSL_VERSION_NUMBER)
 	if (global_ssl.async)
 		mode |= SSL_MODE_ASYNC;
 #endif
@@ -4526,7 +4532,7 @@ int ssl_sock_handshake(struct connection
 				fd_cant_recv(conn->t.sock.fd);
 				return 0;
 			}
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if (OPENSSL_VERSION_NUMBER >= 0x1010000fL) && !defined(LIBRESSL_VERSION_NUMBER)
 			else if (ret == SSL_ERROR_WANT_ASYNC) {
 				ssl_async_process_fds(conn, conn->xprt_ctx);
 				return 0;
@@ -4610,7 +4616,7 @@ int ssl_sock_handshake(struct connection
 			fd_cant_recv(conn->t.sock.fd);
 			return 0;
 		}
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if (OPENSSL_VERSION_NUMBER >= 0x1010000fL) && !defined(LIBRESSL_VERSION_NUMBER)
 		else if (ret == SSL_ERROR_WANT_ASYNC) {
 			ssl_async_process_fds(conn, conn->xprt_ctx);
 			return 0;
@@ -4802,7 +4808,7 @@ static int ssl_sock_to_buf(struct connec
 				fd_cant_recv(conn->t.sock.fd);
 				break;
 			}
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if (OPENSSL_VERSION_NUMBER >= 0x1010000fL) && !defined(LIBRESSL_VERSION_NUMBER)
 			else if (ret == SSL_ERROR_WANT_ASYNC) {
 				ssl_async_process_fds(conn, conn->xprt_ctx);
 				break;
@@ -4910,7 +4916,7 @@ static int ssl_sock_from_buf(struct conn
 				__conn_sock_want_recv(conn);
 				break;
 			}
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if (OPENSSL_VERSION_NUMBER >= 0x1010000fL) && !defined(LIBRESSL_VERSION_NUMBER)
 			else if (ret == SSL_ERROR_WANT_ASYNC) {
 				ssl_async_process_fds(conn, conn->xprt_ctx);
 				break;
@@ -4933,7 +4939,7 @@ static int ssl_sock_from_buf(struct conn
 static void ssl_sock_close(struct connection *conn) {
 
 	if (conn->xprt_ctx) {
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if (OPENSSL_VERSION_NUMBER >= 0x1010000fL) && !defined(LIBRESSL_VERSION_NUMBER)
 		if (global_ssl.async) {
 			OSSL_ASYNC_FD all_fd[32], afd;
 			size_t num_all_fds = 0;
