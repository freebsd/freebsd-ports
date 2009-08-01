--- plugins/nautilus/seahorse-tool.c.orig	2009-08-01 15:27:07.000000000 -0400
+++ plugins/nautilus/seahorse-tool.c	2009-08-01 15:23:46.000000000 -0400
@@ -171,6 +171,9 @@ prompt_recipients (gpgme_key_t *signkey)
         
         if (recips) {
             
+	    gpgme_check_version (NULL);
+	    gerr = gpgme_engine_check_version (GPGME_PROTOCOL_OpenPGP);
+	    g_return_val_if_fail (GPG_IS_OK (gerr), NULL);
             gerr = gpgme_new (&ctx);
             g_return_val_if_fail (GPG_IS_OK (gerr), NULL);
         
@@ -327,6 +330,10 @@ prompt_signer ()
             
         id = cryptui_keyset_key_raw_keyid (keyset, signer);
         g_free (signer);
+
+	gpgme_check_version (NULL);
+	gerr = gpgme_engine_check_version (GPGME_PROTOCOL_OpenPGP);
+	g_return_val_if_fail (GPG_IS_OK (gerr), NULL);
         
         gerr = gpgme_new (&ctx);
         g_return_val_if_fail (GPG_IS_OK (gerr), NULL);
