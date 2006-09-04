--- pam_smbpass/pam_smb_passwd.c.orig	Thu Apr 20 04:29:22 2006
+++ pam_smbpass/pam_smb_passwd.c	Thu Aug 24 01:30:57 2006
@@ -226,7 +226,7 @@
                                    (const void **)&pass_old );
         } else {
             retval = pam_get_data( pamh, _SMB_OLD_AUTHTOK,
-                                   (const void **)&pass_old );
+                                   (void **)&pass_old );
             if (retval == PAM_NO_MODULE_DATA) {
 		pass_old = NULL;
                 retval = PAM_SUCCESS;
