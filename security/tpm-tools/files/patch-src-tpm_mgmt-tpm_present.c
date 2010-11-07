--- src/tpm_mgmt/tpm_present.c.orig	2009-08-20 23:46:31.000000000 +0900
+++ src/tpm_mgmt/tpm_present.c	2010-10-25 01:55:31.071556276 +0900
@@ -168,7 +168,7 @@
 	TSS_HPOLICY hTpmPolicy;
 	char *pwd = NULL;
 	int pswd_len;
-	char rsp[5];
+	char rsp[6];
 	int scanCount;
 
 	//get status w/o owner auth (FAILS 1.1, should PASS 1.2)
