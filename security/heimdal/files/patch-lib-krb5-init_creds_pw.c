--- lib/krb5/init_creds_pw.c.orig	2020-03-12 13:34:52 UTC
+++ lib/krb5/init_creds_pw.c
@@ -2273,6 +2273,7 @@ krb5_init_creds_step(krb5_context context,
 				       &ctx->req_buffer,
 				       NULL,
 				       NULL);
+#ifdef PKINIT
 	    if (ret == 0 && ctx->pk_init_ctx) {
 		PA_DATA *pa_pkinit_kx;
 		int idx = 0;
@@ -2293,6 +2294,7 @@ krb5_init_creds_step(krb5_context context,
 		else if (pa_pkinit_kx != NULL)
 		    ctx->ic_flags |= KRB5_INIT_CREDS_PKINIT_KX_VALID;
 	    }
+#endif
 	    if (ret == 0)
 		ret = copy_EncKDCRepPart(&rep.enc_part, &ctx->enc_part);
 
