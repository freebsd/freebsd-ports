--- auth/pam.c.orig	2007-06-11 21:41:12.000000000 -0400
+++ auth/pam.c	2007-07-22 21:02:46.956010000 -0400
@@ -94,7 +94,9 @@
 	log_error(USE_ERRNO|NO_EXIT|NO_MAIL, "unable to initialize PAM");
 	return(AUTH_FATAL);
     }
-    if (strcmp(user_tty, "unknown"))
+    if (strcmp(user_tty, "unknown") == 0)
+	(void) pam_set_item(pamh, PAM_TTY, "");
+    else
 	(void) pam_set_item(pamh, PAM_TTY, user_tty);
 
     return(AUTH_SUCCESS);
