--- src/tpm_mgmt/tpm_present.c.orig	2012-05-17 17:49:58 UTC
+++ src/tpm_mgmt/tpm_present.c
@@ -168,9 +168,10 @@ static BOOL confirmLifeLock(TSS_HCONTEXT
 	TSS_HPOLICY hTpmPolicy;
 	char *pwd = NULL;
 	int pswd_len;
-	char rsp[5];
+	char rsp[6];
 	int scanCount;
 
+	memset(&hTpmPolicy, 0, sizeof(hTpmPolicy));
 	//get status w/o owner auth (FAILS 1.1, should PASS 1.2)
 	if (tpmGetStatus(hTpm, flags[cmdEnable].property, &bCmd) !=
 	    TSS_SUCCESS
