--- source3/librpc/crypto/gse.c.orig	2017-05-23 08:19:23 UTC
+++ source3/librpc/crypto/gse.c
@@ -334,11 +334,12 @@ static NTSTATUS gse_get_client_auth_toke
 	struct gse_context *gse_ctx =
 		talloc_get_type_abort(gensec_security->private_data,
 				      struct gse_context);
-	OM_uint32 gss_maj, gss_min;
+	OM_uint32 gss_min;
 	gss_buffer_desc in_data;
 	gss_buffer_desc out_data;
 	DATA_BLOB blob = data_blob_null;
 	NTSTATUS status;
+	OM_uint32 gss_maj = -1;
 	OM_uint32 time_rec = 0;
 	struct timeval tv;
 	struct cli_credentials *cli_creds = gensec_get_credentials(gensec_security);
