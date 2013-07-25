--- src/tpm_mgmt/tpm_present.c.orig	2009-08-20 23:46:31.000000000 +0900
+++ src/tpm_mgmt/tpm_present.c	2013-07-24 22:02:07.000000000 +0900
@@ -168,9 +168,10 @@
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
