--- ./pam_smbpass/pam_smb_auth.c.orig	Fri Jun 23 15:16:50 2006
+++ ./pam_smbpass/pam_smb_auth.c	Tue Apr 17 02:06:59 2007
@@ -167,7 +167,7 @@
 
     retval = PAM_SUCCESS;
 
-    pam_get_data(pamh, "smb_setcred_return", (const void **) &pretval);
+    pam_get_data(pamh, "smb_setcred_return", (void **) &pretval);
     if(pretval) {
 	retval = *pretval;
 	SAFE_FREE(pretval);
