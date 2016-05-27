http://sourceforge.net/mailarchive/message.php?msg_name=4C0E2D48.20803%40sirrix.com

--- e_tpm_err.c.orig	2011-01-20 18:24:04 UTC
+++ e_tpm_err.c
@@ -235,6 +235,7 @@ static ERR_STRING_DATA TPM_str_functs[] 
 	{ERR_PACK(0, TPM_F_TPM_BIND_FN, 0), "TPM_BIND_FN"},
 	{ERR_PACK(0, TPM_F_TPM_FILL_RSA_OBJECT, 0), "TPM_FILL_RSA_OBJECT"},
 	{ERR_PACK(0, TPM_F_TPM_ENGINE_GET_AUTH, 0), "TPM_ENGINE_GET_AUTH"},
+	{ERR_PACK(0, TPM_F_TPM_BIO_FROM_NVRAM, 0), "TPM_BIO_FROM_NVRAM"},
 	{0, NULL}
 };
 
@@ -265,6 +266,7 @@ static ERR_STRING_DATA TPM_str_reasons[]
 	{TPM_R_FILE_READ_FAILED, "failed reading the key file"},
 	{TPM_R_ID_INVALID, "engine id doesn't match"},
 	{TPM_R_UI_METHOD_FAILED, "ui function failed"},
+	{TPM_R_NVRAM_FAILED, "nvram failure"},
 	{0, NULL}
 };
 
