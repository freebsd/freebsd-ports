--- nsswitch/pam_winbind.c.orig	Sun May 28 02:21:10 2006
+++ nsswitch/pam_winbind.c	Sun May 28 02:22:16 2006
@@ -997,7 +997,7 @@
 		}
 		return PAM_USER_UNKNOWN;
 	case 0:
-		pam_get_data( pamh, PAM_WINBIND_NEW_AUTHTOK_REQD, (const void **)&tmp);
+		pam_get_data( pamh, PAM_WINBIND_NEW_AUTHTOK_REQD, (void **)&tmp);
 		if (tmp != NULL) {
 			retval = atoi(tmp);
 			switch (retval) {
@@ -1300,7 +1300,7 @@
 		 * By reaching here we have approved the passwords and must now
 		 * rebuild the password database file.
 		 */
-		pam_get_data( pamh, PAM_WINBIND_PWD_LAST_SET, (const void **)&pwdlastset_update);
+		pam_get_data( pamh, PAM_WINBIND_PWD_LAST_SET, (void **)&pwdlastset_update);
 
 		retval = winbind_chauthtok_request(pamh, ctrl, user, pass_old, pass_new, pwdlastset_update);
 		if (retval) {
