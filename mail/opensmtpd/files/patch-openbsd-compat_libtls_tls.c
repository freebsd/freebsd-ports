--- openbsd-compat/libtls/tls.c.orig	2024-09-04 07:11:38 UTC
+++ openbsd-compat/libtls/tls.c
@@ -635,10 +635,10 @@ tls_configure_ssl_verify(struct tls *ctx, SSL_CTX *ssl
 
 	/* If no CA has been specified, attempt to load the default. */
 	if (ctx->config->ca_mem == NULL && ctx->config->ca_path == NULL) {
-		if (tls_config_load_file(&ctx->error, "CA", tls_default_ca_cert_file(),
-		    &ca_mem, &ca_len) != 0)
+		if (!SSL_CTX_set_default_verify_paths(ssl_ctx)) {
+			tls_set_error(ctx, TLS_ERROR_UNKNOWN, "failed to load default trust store");
 			goto err;
-		ca_free = ca_mem;
+		}
 	}
 
 	if (ca_mem != NULL) {
