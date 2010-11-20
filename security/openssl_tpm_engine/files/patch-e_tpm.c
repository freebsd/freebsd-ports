http://sourceforge.net/mailarchive/message.php?msg_name=4C0E2D48.20803%40sirrix.com
http://sourceforge.net/mailarchive/message.php?msg_name=1270748622.4478.6722.camel%40macbook.infradead.org

--- e_tpm.c.orig	2007-02-06 05:32:10.000000000 +0900
+++ e_tpm.c	2010-11-21 06:54:21.792744937 +0900
@@ -35,9 +35,6 @@
 #include <openssl/bn.h>
 
 #include <tss/platform.h>
-#include <tss/tcpa_defines.h>
-#include <tss/tcpa_typedef.h>
-#include <tss/tcpa_struct.h>
 #include <tss/tss_defines.h>
 #include <tss/tss_typedef.h>
 #include <tss/tss_structs.h>
@@ -45,6 +42,7 @@
 #include <tss/tspi.h>
 
 #include <trousers/trousers.h>  // XXX DEBUG
+#include <trousers/tss.h>  // XXX DEBUG
 
 #include "e_tpm.h"
 
@@ -77,6 +75,11 @@
 static const char *TPM_F_Policy_SetSecret = "Tspi_Policy_SetSecret";
 static const char *TPM_F_Policy_AssignToObject = "Tspi_Policy_AssignToObject";
 
+/* Added by c.hol...@sirrix.com */
+static const char *TPM_F_PcrComposite_SelectPcrIndex = "Tspi_PcrComposite_SelectPcrIndex";
+static const char *TPM_F_TPM_Quote = "Tspi_TPM_Quote";
+static const char *TPM_F_NV_ReadValue = "Tspi_NV_ReadValue";
+
 /* engine specific functions */
 static int tpm_engine_destroy(ENGINE *);
 static int tpm_engine_init(ENGINE *);
@@ -106,6 +109,8 @@
 #define TPM_CMD_SO_PATH		ENGINE_CMD_BASE
 #define TPM_CMD_PIN		ENGINE_CMD_BASE+1
 #define TPM_CMD_SECRET_MODE	ENGINE_CMD_BASE+2
+#define TPM_CMD_QUOTE		ENGINE_CMD_BASE+3
+
 static const ENGINE_CMD_DEFN tpm_cmd_defns[] = {
 	{TPM_CMD_SO_PATH,
 	 "SO_PATH",
@@ -119,6 +124,10 @@
 	 "SECRET_MODE",
 	 "The TSS secret mode for all secrets",
 	 ENGINE_CMD_FLAG_NUMERIC},
+	{TPM_CMD_QUOTE,
+	 "QUOTE",
+	 "Perform a TPM_Quote() with the given structure",
+	 ENGINE_CMD_FLAG_NUMERIC},
 	{0, NULL, NULL, 0}
 };
 
@@ -201,6 +210,11 @@
 static unsigned int (*p_tspi_Policy_SetSecret)();
 static unsigned int (*p_tspi_Policy_AssignToObject)();
 
+/* Added by c.hol...@sirrix.com */
+static unsigned int (*p_tspi_PcrComposite_SelectPcrIndex)();
+static unsigned int (*p_tspi_TPM_Quote)();
+static unsigned int (*p_tspi_NV_ReadValue)();
+
 /* This internal function is used by ENGINE_tpm() and possibly by the
  * "dynamic" ENGINE support too */
 static int bind_helper(ENGINE * e)
@@ -255,6 +269,9 @@
 	UINT32 authusage;
 	BYTE *auth;
 
+	/* Added by c.hol...@sirrix.com */
+	BYTE well_known[TPM_SHA1_160_HASH_LEN] = TSS_WELL_KNOWN_SECRET;
+
 	if (hSRK != NULL_HKEY) {
 		DBGFN("SRK is already loaded.");
 		return 1;
@@ -300,29 +317,37 @@
 		return 0;
 	}
 
-	if ((auth = calloc(1, 128)) == NULL) {
-		TSSerr(TPM_F_TPM_LOAD_SRK, ERR_R_MALLOC_FAILURE);
-		return 0;
-	}
+	/* c.hol...@sirrix.com: If the UI method is NULL, use TSS_WELL_KNOWN_SECRET */
+	if (ui) {
+		if ((auth = calloc(1, 128)) == NULL) {
+			TSSerr(TPM_F_TPM_LOAD_SRK, ERR_R_MALLOC_FAILURE);
+			return 0;
+		}
 
-	if (!tpm_engine_get_auth(ui, (char *)auth, 128, "SRK authorization: ")) {
-		p_tspi_Context_CloseObject(hContext, hSRK);
-		free(auth);
-		TSSerr(TPM_F_TPM_LOAD_SRK, TPM_R_REQUEST_FAILED);
-	}
+		if (!tpm_engine_get_auth(ui, (char *)auth, 128, "SRK authorization: ")) {
+			p_tspi_Context_CloseObject(hContext, hSRK);
+			free(auth);
+			TSSerr(TPM_F_TPM_LOAD_SRK, TPM_R_REQUEST_FAILED);
+		}
+		/* secret_mode is a global that may be set by engine ctrl
+		 * commands.  By default, its set to TSS_SECRET_MODE_PLAIN */
+		if ((result = p_tspi_Policy_SetSecret(hSRKPolicy, secret_mode,
+						      strlen((char *)auth), auth))) {
+			p_tspi_Context_CloseObject(hContext, hSRK);
+			free(auth);
+			TSSerr(TPM_F_TPM_LOAD_SRK, TPM_R_REQUEST_FAILED);
+			return 0;
+		}
 
-	/* secret_mode is a global that may be set by engine ctrl
-	 * commands.  By default, its set to TSS_SECRET_MODE_PLAIN */
-	if ((result = p_tspi_Policy_SetSecret(hSRKPolicy, secret_mode,
-					      strlen((char *)auth), auth))) {
-		p_tspi_Context_CloseObject(hContext, hSRK);
 		free(auth);
-		TSSerr(TPM_F_TPM_LOAD_SRK, TPM_R_REQUEST_FAILED);
-		return 0;
+	} else {
+		if (result = p_tspi_Policy_SetSecret(hSRKPolicy, TSS_SECRET_MODE_SHA1, 20, well_known)) {
+			p_tspi_Context_CloseObject(hContext, hSRK);
+			TSSerr(TPM_F_TPM_LOAD_SRK, TPM_R_REQUEST_FAILED);
+			return 0;
+		}
 	}
 
-	free(auth);
-
 	return 1;
 }
 
@@ -363,6 +388,12 @@
 	void (*p22) ();
 	void (*p23) ();
 	void (*p24) ();
+
+	/* Added by c.hol...@sirrix.com */
+	void (*p25) ();
+	void (*p26) ();
+	void (*p27) ();
+
 	TSS_RESULT result;
 
 	DBG("%s", __FUNCTION__);
@@ -400,6 +431,12 @@
 	    !(p21 = DSO_bind_func(tpm_dso, TPM_F_Context_GetTpmObject)) ||
 	    !(p22 = DSO_bind_func(tpm_dso, TPM_F_GetAttribUint32)) ||
 	    !(p23 = DSO_bind_func(tpm_dso, TPM_F_SetAttribData)) ||
+
+	    /* Added by c.hol...@sirrix.com */
+	    !(p25 = DSO_bind_func(tpm_dso, TPM_F_TPM_Quote)) ||
+	    !(p26 = DSO_bind_func(tpm_dso, TPM_F_PcrComposite_SelectPcrIndex)) ||
+	    !(p27 = DSO_bind_func(tpm_dso, TPM_F_NV_ReadValue)) ||
+
 	    !(p24 = DSO_bind_func(tpm_dso, TPM_F_Policy_AssignToObject))
 	    ) {
 		TSSerr(TPM_F_TPM_ENGINE_INIT, TPM_R_DSO_FAILURE);
@@ -432,6 +469,11 @@
 	p_tspi_SetAttribData = (unsigned int (*) ()) p23;
 	p_tspi_Policy_AssignToObject = (unsigned int (*) ()) p24;
 
+	/* Added by c.hol...@sirrix.com */
+	p_tspi_TPM_Quote = (unsigned int (*) ()) p25;
+	p_tspi_PcrComposite_SelectPcrIndex = (unsigned int (*) ()) p26;
+	p_tspi_NV_ReadValue = (unsigned int (*) ()) p27;
+
 	if ((result = p_tspi_Context_Create(&hContext))) {
 		TSSerr(TPM_F_TPM_ENGINE_INIT, TPM_R_UNIT_FAILURE);
 		goto err;
@@ -487,6 +529,11 @@
 	p_tspi_TPM_StirRandom = NULL;
 	p_tspi_TPM_GetRandom = NULL;
 
+	/* Added by c.hol...@sirrix.com */
+	p_tspi_TPM_Quote = NULL;
+	p_tspi_PcrComposite_SelectPcrIndex = NULL;
+	p_tspi_NV_ReadValue = NULL;
+
 	return 0;
 }
 
@@ -612,6 +659,55 @@
 	return 1;
 }
 
+/*
+ *	Read a keyblob from NVRAM into an OpenSSL memory BIO
+ *		by Christian Holler (c.hol...@sirrix.com), Sirrix AG
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
+				  &hNVStore);
+	
+	if (result != TSS_SUCCESS) {
+		TSSerr(TPM_F_TPM_BIO_FROM_NVRAM,
+		       TPM_R_REQUEST_FAILED);
+		return 0;
+	}
+	
+	/* Set the index to be read */
+	result = p_tspi_SetAttribUint32(hNVStore, TSS_TSPATTRIB_NV_INDEX, 0,
+			     (UINT32) index);
+
+	if (result != TSS_SUCCESS) {
+		TSSerr(TPM_F_TPM_BIO_FROM_NVRAM,
+		       TPM_R_REQUEST_FAILED);
+		return 0;
+	}
+
+	result = p_tspi_NV_ReadValue(hNVStore, 0, &length, &dataRead);
+	BIO_write(mem, dataRead, length);
+	p_tspi_Context_FreeMemory(hContext, dataRead);
+
+	if (result != TSS_SUCCESS ) {
+		TSSerr(TPM_F_TPM_BIO_FROM_NVRAM,
+		       TPM_R_REQUEST_FAILED);
+		return 0;
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
@@ -627,7 +723,7 @@
 
 	DBG("%s", __FUNCTION__);
 
-	if (!key_id) {
+	if (!key_id && !cb_data) {
 		TSSerr(TPM_F_TPM_ENGINE_LOAD_KEY, ERR_R_PASSED_NULL_PARAMETER);
 		return NULL;
 	}
@@ -637,10 +733,21 @@
 		return NULL;
 	}
 
-	if ((bf = BIO_new_file(key_id, "r")) == NULL) {
-		TSSerr(TPM_F_TPM_ENGINE_LOAD_KEY,
-		       TPM_R_FILE_NOT_FOUND);
-		return NULL;
+	if (cb_data) {
+		struct nvram_request *nvreq = cb_data;
+
+		if (!BIO_from_nvram(nvreq->index, nvreq->length, &bf)) {
+			TSSerr(TPM_F_TPM_ENGINE_LOAD_KEY,
+				TPM_R_NVRAM_FAILED);
+			return NULL;
+		}
+	} else {
+
+		if ((bf = BIO_new_file(key_id, "r")) == NULL) {
+			TSSerr(TPM_F_TPM_ENGINE_LOAD_KEY,
+			       TPM_R_FILE_NOT_FOUND);
+			return NULL;
+		}
 	}
 retry:
 	if ((rc = BIO_read(bf, &blob_buf[0], 4096)) < 0) {
@@ -746,6 +853,8 @@
 		return NULL;
 	}
 
+	EVP_PKEY_assign_RSA(pkey, rsa);
+
 	return pkey;
 }
 
@@ -782,6 +891,70 @@
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
+		return 0;
+	}
+
+	/* Key is invalid */
+	if (app_data->hKey == NULL_HKEY) {
+		TSSerr(TPM_F_TPM_QUOTE, TPM_R_INVALID_KEY);
+		return 0;
+	}
+
+	/* Set up PcrComposite Structure, this is a set 
+	 * of PCRs which will be used for the quote */
+	result =
+		p_tspi_Context_CreateObject(hContext, TSS_OBJECT_TYPE_PCRS,
+				TSS_PCRS_STRUCT_INFO, &hPcrComposite);
+	if (result != TSS_SUCCESS) {
+		TSSerr(TPM_F_TPM_QUOTE, TPM_R_REQUEST_FAILED);
+		return 0;
+	}
+
+	/* Add all PCR values to be used to PcrComposite structure */
+	for (i = 0; i < request->PCRSelLength; i++) {
+		if (request->PCRSel[i]) {
+			result = p_tspi_PcrComposite_SelectPcrIndex(hPcrComposite, i);
+
+			if (result != TSS_SUCCESS) {
+				TSSerr(TPM_F_TPM_QUOTE, TPM_R_REQUEST_FAILED);
+				return 0;
+			}
+		}
+	}
+
+	/* Set the nonce */
+	tssVal.rgbExternalData = request->nonce;
+	tssVal.ulExternalDataLength = SHA_DIGEST_LENGTH;
+
+	result = p_tspi_TPM_Quote(hTPM, app_data->hKey, hPcrComposite, &tssVal);
+
+	if (result != TSS_SUCCESS) {
+		TSSerr(TPM_F_TPM_QUOTE, TPM_R_REQUEST_FAILED);
+		return 0;
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
 	int initialised = ((tpm_dso == NULL) ? 0 : 1);
@@ -820,6 +993,8 @@
 			return 1;
 		case TPM_CMD_PIN:
 			return tpm_create_srk_policy(p);
+		case TPM_CMD_QUOTE:
+			return tpm_quote(p);
 		default:
 			break;
 	}
@@ -1104,7 +1279,12 @@
 	}
 
 	if (app_data->sigScheme == TSS_SS_RSASSAPKCS1V15_SHA1) {
-		if (flen != SHA_DIGEST_LENGTH) {
+		/* c.hol...@sirrix.com: Ugly hack, OpenSSL passes PKCS1v1.5 wrapped hash, 
+		 * original SHA1 is last 20 bytes */
+		if (flen == SHA_DIGEST_LENGTH+15) {
+			from += 15;
+			flen = SHA_DIGEST_LENGTH;
+		} else if (flen != SHA_DIGEST_LENGTH) {
 			TSSerr(TPM_F_TPM_RSA_PRIV_ENC, TPM_R_INVALID_MSG_SIZE);
 			return 0;
 		}
