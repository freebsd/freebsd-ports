--- ./nsswitch/pam_winbind.c.orig	Mon Apr  9 19:30:57 2007
+++ ./nsswitch/pam_winbind.c	Tue Apr 17 02:06:59 2007
@@ -1735,7 +1735,7 @@
 		ret = PAM_USER_UNKNOWN;
 		goto out;
 	case 0:
-		pam_get_data( pamh, PAM_WINBIND_NEW_AUTHTOK_REQD, (const void **)&tmp);
+		pam_get_data( pamh, PAM_WINBIND_NEW_AUTHTOK_REQD, (void **)&tmp);
 		if (tmp != NULL) {
 			ret = atoi((const char *)tmp);
 			switch (ret) {
