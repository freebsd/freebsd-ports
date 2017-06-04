rc/ssl_sock.c.orig	2017-05-12 15:18:50 UTC
+++ src/ssl_sock.c
@@ -768,7 +768,7 @@ static int ssl_sock_load_ocsp(SSL_CTX *c
 	unsigned char *p;
 	pem_password_cb *passwd_cb;
 	void *passwd_cb_userdata;
-	void (*callback) (void);
+	void (*callback) (void) = NULL;
 
 	snprintf(ocsp_path, MAXPATHLEN+1, "%s.ocsp", cert_path);
 
@@ -842,10 +842,14 @@ static int ssl_sock_load_ocsp(SSL_CTX *c
 		ocsp = NULL;
 
 #ifndef SSL_CTX_get_tlsext_status_cb
-# define SSL_CTX_get_tlsext_status_cb(ctx, cb) \
-	*cb = (void (*) (void))ctx->tlsext_status_cb;
+#ifndef SSL_CTRL_GET_TLSEXT_STATUS_REQ_CB
+#define SSL_CTRL_GET_TLSEXT_STATUS_REQ_CB 128
 #endif
+	long temp_callback = SSL_CTX_ctrl(ctx, SSL_CTRL_GET_TLSEXT_STATUS_REQ_CB, 0, callback);
+	callback = (void*) &temp_callback;
+#else
 	SSL_CTX_get_tlsext_status_cb(ctx, &callback);
+#endif
 
 	if (!callback) {
 		struct ocsp_cbk_arg *cb_arg = calloc(1, sizeof(*cb_arg));
@@ -871,7 +875,10 @@ static int ssl_sock_load_ocsp(SSL_CTX *c
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
