--- src/data_mgmt/data_protect.c.orig	2012-05-17 17:49:58 UTC
+++ src/data_mgmt/data_protect.c
@@ -437,6 +437,7 @@ main( int    a_iArgc,
 	CK_OBJECT_HANDLE   hObject;
 	CK_MECHANISM       tMechanism = { CKM_AES_ECB, NULL, 0 };
 
+	memset(&hSession, 0, sizeof(hSession));
 	// Set up i18n
 	initIntlSys( );
 
