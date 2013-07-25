--- src/data_mgmt/data_protect.c.orig	2013-07-24 22:04:32.000000000 +0900
+++ src/data_mgmt/data_protect.c	2013-07-24 22:04:59.000000000 +0900
@@ -425,6 +425,7 @@
 	CK_OBJECT_HANDLE   hObject;
 	CK_MECHANISM       tMechanism = { CKM_AES_ECB, NULL, 0 };
 
+	memset(&hSession, 0, sizeof(hSession));
 	// Set up i18n
 	initIntlSys( );
 
