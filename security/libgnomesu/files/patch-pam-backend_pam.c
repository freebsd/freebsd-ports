--- pam-backend/pam.c.orig	Wed Jan 12 07:16:27 2005
+++ pam-backend/pam.c	Fri Jan 14 14:14:42 2005
@@ -17,7 +17,7 @@
  */
 
 #include <security/pam_appl.h>
-#include <security/pam_misc.h>
+#include <security/pam_mod_misc.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/types.h>
@@ -276,7 +276,6 @@
 		#ifdef HAVE_SETFSUID
 		setfsuid (pw->pw_uid);
 		#endif /* HAVE_SETFSUID */
-		change_identity (pw);
 		initgroups (pw->pw_name, pw->pw_gid);
 		setgid (pw->pw_gid);
 		setuid (pw->pw_uid);
