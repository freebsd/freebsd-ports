--- pam_abl.c.orig	Wed Oct 12 21:22:26 2005
+++ pam_abl.c	Sat Jan 14 21:39:41 2006
@@ -344,7 +344,7 @@
         abl_args *args = data;
         log_debug(args, "In cleanup, err is %08x", err);
 
-        if (err && (err & PAM_DATA_REPLACE) == 0) {
+        if (err == PAM_AUTH_ERR) {
             record_attempt(args);
         }
         config_free(args);
@@ -359,6 +359,12 @@
     int err = PAM_SUCCESS;
 
     /*log_debug(NULL, "pam_sm_authenticate(), flags=%08x", flags);*/
+
+    if (err = pam_get_data(pamh, DATA_NAME, &args), PAM_SUCCESS == err) {
+        record_attempt(args);
+    } else if (PAM_NO_MODULE_DATA != err) {
+       return err;
+    }
 
     if (args = malloc(sizeof(abl_args)), NULL == args) {
         return PAM_BUF_ERR;
