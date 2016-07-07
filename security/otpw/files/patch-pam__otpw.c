--- pam_otpw.c.orig	2014-08-07 19:21:15 UTC
+++ pam_otpw.c
@@ -25,6 +25,9 @@
 #define PAM_SM_AUTH
 #define PAM_SM_SESSION
 #include <security/pam_modules.h>
+#ifdef OPENPAM
+#include <security/pam_appl.h>
+#endif
 
 #include "otpw.h"
 
@@ -226,8 +229,13 @@ PAM_EXTERN int pam_sm_authenticate(pam_h
   
   /* get user name */
   retval = pam_get_user(pamh, &username, "login: ");
+#ifdef OPENPAM
+  if (retval == PAM_CONV_ERR)
+    return PAM_CONV_ERR;
+#else
   if (retval == PAM_CONV_AGAIN)
     return PAM_INCOMPLETE;
+#endif
   else if (retval != PAM_SUCCESS) {
     log_message(LOG_NOTICE, pamh, "no username provided");
     return PAM_USER_UNKNOWN;
