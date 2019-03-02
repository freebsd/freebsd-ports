--- src/e_tpm.h.orig	2017-12-18 15:45:34 UTC
+++ src/e_tpm.h
@@ -66,6 +66,8 @@ void ERR_TSS_error(int function, int reason, char *fil
 #define TPM_F_TPM_FILL_RSA_OBJECT		116
 #define TPM_F_TPM_ENGINE_GET_AUTH		117
 #define TPM_F_TPM_CREATE_SRK_POLICY		118
+#define TPM_F_TPM_BIO_FROM_NVRAM		119
+#define TPM_F_TPM_QUOTE				120
 
 /* Reason codes. */
 #define TPM_R_ALREADY_LOADED			100
@@ -96,6 +98,7 @@ void ERR_TSS_error(int function, int reason, char *fil
 #define TPM_R_ID_INVALID			125
 #define TPM_R_UI_METHOD_FAILED			126
 #define TPM_R_UNKNOWN_SECRET_MODE		127
+#define TPM_R_NVRAM_FAILED			128
 
 /* structure pointed to by the RSA object's app_data pointer */
 struct rsa_app_data
@@ -105,6 +108,25 @@ struct rsa_app_data
 	TSS_HENCDATA hEncData;
 	UINT32 encScheme;
 	UINT32 sigScheme;
+};
+
+/* Added by c.hol...@sirrix.com */
+struct quote_request
+{
+	RSA* rsa;
+	unsigned int PCRSel[256];
+	unsigned int PCRSelLength;
+	const unsigned char* nonce;
+	unsigned int nonceLen;
+	unsigned char* rgbData;
+	unsigned int ulValidationDataLength;
+	unsigned char* rgbValidationData;
+};
+
+struct nvram_request
+{
+	unsigned int index;
+	unsigned int length;
 };
 
 #define TPM_ENGINE_EX_DATA_UNINIT		-1
