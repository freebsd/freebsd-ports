diff --git a/etc/afpd/afp_options.c etc/afpd/afp_options.c
index ebc9a65..057a1a3 100644
--- a/etc/afpd/afp_options.c
+++ etc/afpd/afp_options.c
@@ -137,8 +137,6 @@ void afp_options_free(struct afp_options *opt,
         free(opt->passwdfile);
     if (opt->signatureopt && (opt->signatureopt != save->signatureopt))
 	free(opt->signatureopt);
-    if (opt->signature && (opt->signature != save->signature))
-        free(opt->signature);
     if (opt->k5service && (opt->k5service != save->k5service))
 	free(opt->k5service);
     if (opt->k5realm && (opt->k5realm != save->k5realm))
