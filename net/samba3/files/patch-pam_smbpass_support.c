--- ./pam_smbpass/support.c.orig	Tue May 23 20:54:32 2006
+++ ./pam_smbpass/support.c	Tue Apr 17 02:06:59 2007
@@ -384,7 +384,7 @@
             if (newauth != NULL) {
 
                 /* any previous failures for this user ? */
-                pam_get_data(pamh, data_name, (const void **) &old);
+                pam_get_data(pamh, data_name, (void **) &old);
 
                 if (old != NULL) {
                     newauth->count = old->count + 1;
@@ -594,7 +594,7 @@
 
         retval = pam_set_data( pamh, data_name, (void *) token, _cleanup );
         if (retval != PAM_SUCCESS
-            || (retval = pam_get_data( pamh, data_name, (const void **)&item ))
+            || (retval = pam_get_data( pamh, data_name, (void **)&item ))
                              != PAM_SUCCESS)
         {
             _log_err( LOG_CRIT, "error manipulating password data [%s]"
