--- libarms/ssl.c.orig	2012-01-24 02:47:27 UTC
+++ libarms/ssl.c
@@ -162,6 +162,7 @@ arms_ssl_servercert_verify_cb(int ok, X509_STORE_CTX *
 {
 	char cn[256];
 	const char *errmsg = NULL;
+	int error;
 
 	X509_NAME_oneline(
 		X509_get_subject_name(
@@ -171,13 +172,15 @@ arms_ssl_servercert_verify_cb(int ok, X509_STORE_CTX *
 		X509_get_issuer_name(
 			X509_STORE_CTX_get_current_cert(ctx)), cn, sizeof(cn));
 
+	error = X509_STORE_CTX_get_error(ctx);
+
 	if (!ok) {
-		switch (ctx->error) {
+		switch (error) {
 		case X509_V_ERR_CERT_NOT_YET_VALID:
 		case X509_V_ERR_CERT_HAS_EXPIRED:
 			/* XXX: ignore Validity Not Before/Not After field */
 			ok = 1;
-			ctx->error = X509_V_OK;
+			X509_STORE_CTX_set_error(ctx, X509_V_OK);
 			break;
 
 		case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY:
@@ -187,7 +190,7 @@ arms_ssl_servercert_verify_cb(int ok, X509_STORE_CTX *
 			break;
 
 		default:
-			errmsg = X509_verify_cert_error_string(ctx->error);
+			errmsg = X509_verify_cert_error_string(error);
 			break;
 		}
 
