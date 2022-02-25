--- relayd/relay.c.orig	2014-08-10 20:08:47 UTC
+++ relayd/relay.c
@@ -2097,7 +2097,7 @@ relay_ssl_ctx_create(struct relay *rlay)
 	/* Verify the server certificate if we have a CA chain */
 	if ((rlay->rl_conf.flags & F_SSLCLIENT) &&
 	    (rlay->rl_ssl_ca != NULL)) {
-		if (!ssl_ctx_load_verify_memory(ctx,
+		if (!SSL_CTX_load_verify_mem(ctx,
 		    rlay->rl_ssl_ca, rlay->rl_conf.ssl_ca_len))
 			goto err;
 		SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER, NULL);
@@ -2107,7 +2107,7 @@ relay_ssl_ctx_create(struct relay *rlay)
 		return (ctx);
 
 	log_debug("%s: loading certificate", __func__);
-	if (!ssl_ctx_use_certificate_chain(ctx,
+	if (!SSL_CTX_use_certificate_chain_mem(ctx,
 	    rlay->rl_ssl_cert, rlay->rl_conf.ssl_cert_len))
 		goto err;
 
@@ -2716,12 +2716,12 @@ relay_load_certfiles(struct relay *rlay)
 		return (-1);
 
 	if (snprintf(certfile, sizeof(certfile),
-	    "/usr/local/etc/ssl/%s:%u.crt", hbuf, useport) == -1)
+	    "%%PREFIX%%/etc/ssl/%s:%u.crt", hbuf, useport) == -1)
 		return (-1);
 	if ((rlay->rl_ssl_cert = relay_load_file(certfile,
 	    &rlay->rl_conf.ssl_cert_len)) == NULL) {
 		if (snprintf(certfile, sizeof(certfile),
-		    "/usr/local/etc/ssl/%s.crt", hbuf) == -1)
+		    "%%PREFIX%%/etc/ssl/%s.crt", hbuf) == -1)
 			return (-1);
 		if ((rlay->rl_ssl_cert = relay_load_file(certfile,
 		    &rlay->rl_conf.ssl_cert_len)) == NULL)
@@ -2732,11 +2732,11 @@ relay_load_certfiles(struct relay *rlay)
 
 	if (useport) {
 		if (snprintf(certfile, sizeof(certfile),
-		    "/usr/local/etc/ssl/private/%s:%u.key", hbuf, useport) == -1)
+		    "%%PREFIX%%/etc/ssl/private/%s:%u.key", hbuf, useport) == -1)
 			return -1;
 	} else {
 		if (snprintf(certfile, sizeof(certfile),
-		    "/usr/local/etc/ssl/private/%s.key", hbuf) == -1)
+		    "%%PREFIX%%/etc/ssl/private/%s.key", hbuf) == -1)
 			return -1;
 	}
 	if ((rlay->rl_ssl_key = ssl_load_key(env, certfile,
