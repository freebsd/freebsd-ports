--- daemon/seahorse-hkp-server.c.orig	2009-08-01 15:25:02.000000000 -0400
+++ daemon/seahorse-hkp-server.c	2009-08-01 15:23:27.000000000 -0400
@@ -467,7 +467,9 @@ seahorse_hkp_server_start(GError **err)
     /* Initialize GPGME context */
     if (gpgme_ctx == NULL) {
         gpgme_protocol_t proto = GPGME_PROTOCOL_OpenPGP;
-        gpgme_error_t err = gpgme_engine_check_version (proto);
+        gpgme_error_t err;
+	gpgme_check_version (NULL);
+        err = gpgme_engine_check_version (proto);
         g_return_val_if_fail (GPG_IS_OK (err), FALSE);
     
         err = gpgme_new (&gpgme_ctx);
