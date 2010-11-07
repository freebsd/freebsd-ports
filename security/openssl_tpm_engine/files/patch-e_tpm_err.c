http://sourceforge.net/mailarchive/message.php?msg_name=4C0E2D48.20803%40sirrix.com

--- e_tpm_err.c.orig	2005-10-06 04:02:16.000000000 +0900
+++ e_tpm_err.c	2010-10-31 23:44:32.217860972 +0900
@@ -246,6 +246,7 @@
 	{ERR_PACK(0, TPM_F_TPM_BIND_FN, 0), "TPM_BIND_FN"},
 	{ERR_PACK(0, TPM_F_TPM_FILL_RSA_OBJECT, 0), "TPM_FILL_RSA_OBJECT"},
 	{ERR_PACK(0, TPM_F_TPM_ENGINE_GET_AUTH, 0), "TPM_ENGINE_GET_AUTH"},
+	{ERR_PACK(0, TPM_F_TPM_BIO_FROM_NVRAM, 0), "TPM_BIO_FROM_NVRAM"},
 	{0, NULL}
 };
 
@@ -276,6 +277,7 @@
 	{TPM_R_FILE_READ_FAILED, "failed reading the key file"},
 	{TPM_R_ID_INVALID, "engine id doesn't match"},
 	{TPM_R_UI_METHOD_FAILED, "ui function failed"},
+	{TPM_R_NVRAM_FAILED, "nvram failure"},
 	{0, NULL}
 };
 
