--- ssh/gssc.c.orig	2022-05-24 16:56:27 UTC
+++ ssh/gssc.c
@@ -75,7 +75,7 @@ static Ssh_gss_stat ssh_gssapi_acquire_cred(struct ssh
         gssctx->maj_stat =
             gss->inquire_cred_by_mech(&gssctx->min_stat, cred,
                                       (gss_OID) GSS_MECH_KRB5,
-                                      GSS_C_NO_NAME,
+                                      NULL,
                                       &time_rec,
                                       NULL,
                                       NULL);
