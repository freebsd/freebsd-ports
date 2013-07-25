--- e_tpm.c.orig	2012-09-20 02:57:45.000000000 +0900
+++ e_tpm.c	2013-07-26 00:25:21.000000000 +0900
@@ -35,6 +35,7 @@
 #include <tss/tspi.h>
 
 #include <trousers/trousers.h>  // XXX DEBUG
+#include <trousers/tss.h>
 
 #include "e_tpm.h"
 
@@ -55,10 +56,10 @@
 /* rsa functions */
 static int tpm_rsa_init(RSA *rsa);
 static int tpm_rsa_finish(RSA *rsa);
-static int tpm_rsa_pub_dec(int, const unsigned char *, unsigned char *, RSA *, int);
-static int tpm_rsa_pub_enc(int, const unsigned char *, unsigned char *, RSA *, int);
-static int tpm_rsa_priv_dec(int, const unsigned char *, unsigned char *, RSA *, int);
-static int tpm_rsa_priv_enc(int, const unsigned char *, unsigned char *, RSA *, int);
+static int tpm_rsa_pub_dec(int, unsigned char *, unsigned char *, RSA *, int);
+static int tpm_rsa_pub_enc(int, unsigned char *, unsigned char *, RSA *, int);
+static int tpm_rsa_priv_dec(int, unsigned char *, unsigned char *, RSA *, int);
+static int tpm_rsa_priv_enc(int, unsigned char *, unsigned char *, RSA *, int);
 //static int tpm_rsa_sign(int, const unsigned char *, unsigned int, unsigned char *, unsigned int *, const RSA *);
 static int tpm_rsa_keygen(RSA *, int, BIGNUM *, BN_GENCB *);
 #endif
@@ -72,6 +73,7 @@
 #define TPM_CMD_SO_PATH		ENGINE_CMD_BASE
 #define TPM_CMD_PIN		ENGINE_CMD_BASE+1
 #define TPM_CMD_SECRET_MODE	ENGINE_CMD_BASE+2
+#define TPM_CMD_QUOTE		ENGINE_CMD_BASE+3
 static const ENGINE_CMD_DEFN tpm_cmd_defns[] = {
 	{TPM_CMD_SO_PATH,
 	 "SO_PATH",
@@ -85,6 +87,10 @@
 	 "SECRET_MODE",
 	 "The TSS secret mode for all secrets",
 	 ENGINE_CMD_FLAG_NUMERIC},
+	{TPM_CMD_QUOTE,
+	"QUOTE",
+	"Perform a TPM_Quote() with the given structure",
+	ENGINE_CMD_FLAG_NUMERIC},
 	{0, NULL, NULL, 0}
 };
 
@@ -167,6 +173,9 @@
 static unsigned int (*p_tspi_GetPolicyObject)();
 static unsigned int (*p_tspi_Policy_SetSecret)();
 static unsigned int (*p_tspi_Policy_AssignToObject)();
+static unsigned int (*p_tspi_PcrComposite_SelectPcrIndex)();
+static unsigned int (*p_tspi_TPM_Quote)();
+static unsigned int (*p_tspi_NV_ReadValue)();
 
 /* Override the real function calls to use our indirect pointers */
 #define Tspi_Context_Create p_tspi_Context_Create
@@ -193,6 +202,9 @@
 #define Tspi_Hash_SetHashValue p_tspi_Hash_SetHashValue
 #define Tspi_Policy_SetSecret p_tspi_Policy_SetSecret
 #define Tspi_Policy_AssignToObject p_tspi_Policy_AssignToObject
+#define	Tspi_PcrComposite_SelectPcrIndex p_tspi_PcrComposite_SelectPcrIndex
+#define	Tspi_TPM_Quote p_tspi_TPM_Quote
+#define	Tspi_NV_ReadValue p_tspi_NV_ReadValue
 #endif /* DLOPEN_TSPI */
 
 /* This internal function is used by ENGINE_tpm() and possibly by the
@@ -248,6 +260,7 @@
 	TSS_RESULT result;
 	UINT32 authusage;
 	BYTE *auth;
+	BYTE well_known[TPM_SHA1_160_HASH_LEN] = TSS_WELL_KNOWN_SECRET;
 
 	if (hSRK != NULL_HKEY) {
 		DBGFN("SRK is already loaded.");
@@ -294,6 +307,7 @@
 		return 0;
 	}
 
+	if (ui) {
 	if ((auth = calloc(1, 128)) == NULL) {
 		TSSerr(TPM_F_TPM_LOAD_SRK, ERR_R_MALLOC_FAILURE);
 		return 0;
@@ -319,6 +333,15 @@
 
 	free(auth);
 
+	} else {
+		if ((result = Tspi_Policy_SetSecret(hSRKPolicy, TSS_SECRET_MODE_SHA1, 20, well_known))) {
+			Tspi_Context_CloseObject(hContext, hSRK);
+			free(auth);
+			TSSerr(TPM_F_TPM_LOAD_SRK, TPM_R_REQUEST_FAILED);
+			return 0;
+		}
+	}
+
 	return 1;
 }
 
@@ -376,7 +399,10 @@
 	    !bind_tspi_func(tpm_dso, Context_GetTpmObject) ||
 	    !bind_tspi_func(tpm_dso, GetAttribUint32) ||
 	    !bind_tspi_func(tpm_dso, SetAttribData) ||
-	    !bind_tspi_func(tpm_dso, Policy_AssignToObject)
+	    !bind_tspi_func(tpm_dso, Policy_AssignToObject) ||
+	    !bind_tspi_func(tpm_dso, PcrComposite_SelectPcrIndex) ||
+	    !bind_tspi_func(tpm_dso, TPM_Quote) ||
+	    !bind_tspi_func(tpm_dso, NV_ReadValue)
 	    ) {
 		TSSerr(TPM_F_TPM_ENGINE_INIT, TPM_R_DSO_FAILURE);
 		goto err;
@@ -438,6 +464,9 @@
 	p_tspi_Policy_AssignToObject = NULL;
 	p_tspi_TPM_StirRandom = NULL;
 	p_tspi_TPM_GetRandom = NULL;
+	p_tspi_PcrComposite_SelectPcrIndex = NULL;
+	p_tspi_TPM_Quote = NULL;
+	p_tspi_NV_ReadValue = NULL;
 #endif
 	return 0;
 }
@@ -566,6 +595,55 @@
 	return 1;
 }
 
+/*
+ *     Read a keyblob from NVRAM into an OpenSSL memory BIO
+ *             by Christian Holler (c.hol...@sirrix.com), Sirrix AG
+ */
+int BIO_from_nvram(unsigned int index, unsigned int length, BIO** bio)
+{
+	TSS_RESULT result;
+	TSS_HNVSTORE hNVStore;
+	BYTE *dataRead = NULL;
+
+	//unsigned int blobLength = 559;
+
+	BIO *mem = BIO_new(BIO_s_mem());
+
+	/* Create TPM NV object */
+	result = p_tspi_Context_CreateObject(hContext, TSS_OBJECT_TYPE_NV, 0,
+				     &hNVStore);
+
+	if (result != TSS_SUCCESS) {
+		 TSSerr(TPM_F_TPM_BIO_FROM_NVRAM,
+			 TPM_R_REQUEST_FAILED);
+		 return 0;
+	}
+
+	/* Set the index to be read */
+	result = p_tspi_SetAttribUint32(hNVStore, TSS_TSPATTRIB_NV_INDEX, 0,
+				(UINT32) index);
+
+	if (result != TSS_SUCCESS) {
+		 TSSerr(TPM_F_TPM_BIO_FROM_NVRAM,
+			 TPM_R_REQUEST_FAILED);
+		 return 0;
+	}
+
+	result = p_tspi_NV_ReadValue(hNVStore, 0, &length, &dataRead);
+	BIO_write(mem, dataRead, length);
+	p_tspi_Context_FreeMemory(hContext, dataRead);
+
+	if (result != TSS_SUCCESS ) {
+		 TSSerr(TPM_F_TPM_BIO_FROM_NVRAM,
+			 TPM_R_REQUEST_FAILED);
+		 return 0;
+	}
+
+	*bio = mem;
+
+	return 1;
+}
+
 static EVP_PKEY *tpm_engine_load_key(ENGINE *e, const char *key_id,
 				     UI_METHOD *ui, void *cb_data)
 {
@@ -580,7 +658,7 @@
 
 	DBG("%s", __FUNCTION__);
 
-	if (!key_id) {
+	if (!key_id && !cb_data) {
 		TSSerr(TPM_F_TPM_ENGINE_LOAD_KEY, ERR_R_PASSED_NULL_PARAMETER);
 		return NULL;
 	}
@@ -590,17 +668,27 @@
 		return NULL;
 	}
 
+	if (cb_data) {
+		struct nvram_request *nvreq = cb_data;
+
+		if (!BIO_from_nvram(nvreq->index, nvreq->length, &bf)) {
+			TSSerr(TPM_F_TPM_ENGINE_LOAD_KEY,
+			    TPM_R_NVRAM_FAILED);
+			return NULL;
+		}
+	} else {
 	if ((bf = BIO_new_file(key_id, "r")) == NULL) {
 		TSSerr(TPM_F_TPM_ENGINE_LOAD_KEY,
-		       TPM_R_FILE_NOT_FOUND);
+			TPM_R_FILE_NOT_FOUND);
 		return NULL;
 	}
+	}
 
 	blobstr = PEM_ASN1_read_bio((void *)d2i_ASN1_OCTET_STRING,
 				    "TSS KEY BLOB", bf, NULL, NULL, NULL);
 	if (!blobstr) {
 		TSSerr(TPM_F_TPM_ENGINE_LOAD_KEY,
-		       TPM_R_FILE_READ_FAILED);
+			TPM_R_FILE_READ_FAILED);
 		BIO_free(bf);
 		return NULL;
 	}
@@ -611,7 +699,7 @@
 						   blobstr->length,
 						   blobstr->data, &hKey))) {
 		TSSerr(TPM_F_TPM_ENGINE_LOAD_KEY,
-		       TPM_R_REQUEST_FAILED);
+			TPM_R_REQUEST_FAILED);
 		return NULL;
 	}
 	ASN1_OCTET_STRING_free(blobstr);
@@ -621,7 +709,7 @@
 					     &authusage))) {
 		Tspi_Context_CloseObject(hContext, hKey);
 		TSSerr(TPM_F_TPM_ENGINE_LOAD_KEY,
-		       TPM_R_REQUEST_FAILED);
+			TPM_R_REQUEST_FAILED);
 		return NULL;
 	}
 
@@ -726,7 +814,7 @@
 							  TSS_POLICY_USAGE,
 							  &hSRKPolicy))) {
 			TSSerr(TPM_F_TPM_CREATE_SRK_POLICY,
-			       TPM_R_REQUEST_FAILED);
+				TPM_R_REQUEST_FAILED);
 			return 0;
 		}
 	}
@@ -740,6 +828,70 @@
 	return 1;
 }
 
+static int tpm_quote(void* p) {
+	TSS_RESULT result;
+	TSS_HPCRS hPcrComposite;
+	TSS_VALIDATION tssVal;
+
+	unsigned int i = 0;
+
+	struct quote_request *request = p;
+
+	struct rsa_app_data *app_data = RSA_get_ex_data(request->rsa, ex_app_data);
+
+	/* No app_data, this is not a TPM Key and we cannot use it for quote */
+	if (!app_data) {
+		 return 0;
+	}
+
+	/* Key is invalid */
+	if (app_data->hKey == NULL_HKEY) {
+		 TSSerr(TPM_F_TPM_QUOTE, TPM_R_INVALID_KEY);
+		 return 0;
+	}
+
+	/* Set up PcrComposite Structure, this is a set
+	 * of PCRs which will be used for the quote */
+	result =
+		 p_tspi_Context_CreateObject(hContext, TSS_OBJECT_TYPE_PCRS,
+				   TSS_PCRS_STRUCT_INFO, &hPcrComposite);
+	if (result != TSS_SUCCESS) {
+		TSSerr(TPM_F_TPM_QUOTE, TPM_R_REQUEST_FAILED);
+		 return 0;
+	}
+
+	/* Add all PCR values to be used to PcrComposite structure */
+	for (i = 0; i < request->PCRSelLength; i++) {
+		 if (request->PCRSel[i]) {
+			  result = p_tspi_PcrComposite_SelectPcrIndex(hPcrComposite, i);
+
+			  if (result != TSS_SUCCESS) {
+				   TSSerr(TPM_F_TPM_QUOTE, TPM_R_REQUEST_FAILED);
+				   return 0;
+			  }
+		 }
+	}
+
+	/* Set the nonce */
+	tssVal.rgbExternalData = request->nonce;
+	tssVal.ulExternalDataLength = SHA_DIGEST_LENGTH;
+
+	result = p_tspi_TPM_Quote(hTPM, app_data->hKey, hPcrComposite, &tssVal);
+
+	if (result != TSS_SUCCESS) {
+		 TSSerr(TPM_F_TPM_QUOTE, TPM_R_REQUEST_FAILED);
+		 return 0;
+	}
+
+	request->rgbData = tssVal.rgbData;
+	request->ulValidationDataLength = tssVal.ulValidationDataLength;
+	request->rgbValidationData = tssVal.rgbValidationData;
+
+	p_tspi_Context_CloseObject(hContext, hPcrComposite);
+
+	return 1;
+}
+
 static int tpm_engine_ctrl(ENGINE * e, int cmd, long i, void *p, void (*f) ())
 {
 	int initialised = !!hContext;
@@ -778,6 +930,8 @@
 			return 1;
 		case TPM_CMD_PIN:
 			return tpm_create_srk_policy(p);
+		case TPM_CMD_QUOTE:
+			return tpm_quote(p);
 		default:
 			break;
 	}
@@ -832,7 +986,7 @@
 }
 
 static int tpm_rsa_pub_dec(int flen,
-			   const unsigned char *from,
+			   unsigned char *from,
 			   unsigned char *to,
 			   RSA *rsa,
 			   int padding)
@@ -851,7 +1005,7 @@
 }
 
 static int tpm_rsa_priv_dec(int flen,
-			    const unsigned char *from,
+			    unsigned char *from,
 			    unsigned char *to,
 			    RSA *rsa,
 			    int padding)
@@ -928,7 +1082,7 @@
 }
 
 static int tpm_rsa_pub_enc(int flen,
-			   const unsigned char *from,
+			   unsigned char *from,
 			   unsigned char *to,
 			   RSA *rsa,
 			   int padding)
@@ -1035,7 +1189,7 @@
 }
 
 static int tpm_rsa_priv_enc(int flen,
-			    const unsigned char *from,
+			    unsigned char *from,
 			    unsigned char *to,
 			    RSA *rsa,
 			    int padding)
@@ -1080,7 +1234,10 @@
 	}
 
 	if (app_data->sigScheme == TSS_SS_RSASSAPKCS1V15_SHA1) {
-		if (flen != SHA_DIGEST_LENGTH) {
+		if (flen == SHA_DIGEST_LENGTH+15) {
+			from += 15;
+			flen = SHA_DIGEST_LENGTH;
+		} else if (flen != SHA_DIGEST_LENGTH) {
 			TSSerr(TPM_F_TPM_RSA_PRIV_ENC, TPM_R_INVALID_MSG_SIZE);
 			return 0;
 		}
