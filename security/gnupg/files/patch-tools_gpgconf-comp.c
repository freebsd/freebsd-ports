--- tools/gpgconf-comp.c.orig	2021-10-10 16:28:51 UTC
+++ tools/gpgconf-comp.c
@@ -676,6 +676,8 @@ static struct
    { TPM2DAEMON_NAME, TPM2DAEMON_DISP_NAME, "gnupg", N_("TPM"),
      GNUPG_MODULE_NAME_TPM2DAEMON, TPM2DAEMON_NAME ".conf",
      known_options_tpm2daemon, NULL, tpm2daemon_runtime_change},
+#else
+     { NULL }, /* Another dummy, to keep the enum in sync with this table */
 #endif
 
    { DIRMNGR_NAME, DIRMNGR_DISP_NAME, "gnupg",   N_("Network"),
