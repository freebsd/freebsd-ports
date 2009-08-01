--- pgp/seahorse-gpgme-source.c.orig	2009-08-01 15:24:28.000000000 -0400
+++ pgp/seahorse-gpgme-source.c	2009-08-01 15:23:24.000000000 -0400
@@ -139,6 +139,7 @@ init_gpgme (gpgme_ctx_t *ctx)
     gpgme_protocol_t proto = GPGME_PROTOCOL_OpenPGP;
     gpgme_error_t err;
  
+    gpgme_check_version (NULL);
     err = gpgme_engine_check_version (proto);
     g_return_val_if_fail (GPG_IS_OK (err), err);
    
