--- pam_module/pam_oslogin_login.cc.orig	2018-10-11 16:53:23 UTC
+++ pam_module/pam_oslogin_login.cc
@@ -14,7 +14,6 @@
 
 #define PAM_SM_ACCOUNT
 #include <security/pam_appl.h>
-#include <security/pam_ext.h>
 #include <security/pam_modules.h>
 #include <sys/stat.h>
 #include <sys/types.h>
@@ -46,7 +45,7 @@ PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, in
   int pam_result = PAM_PERM_DENIED;
   const char *user_name;
   if ((pam_result = pam_get_user(pamh, &user_name, NULL)) != PAM_SUCCESS) {
-    pam_syslog(pamh, LOG_INFO, "Could not get pam user.");
+    syslog(LOG_INFO, "Could not get pam user.");
     return pam_result;
   }
   string str_user_name(user_name);
@@ -93,7 +92,7 @@ PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, in
       chown(users_filename.c_str(), 0, 0);
       chmod(users_filename.c_str(), S_IRUSR | S_IWUSR | S_IRGRP);
     }
-    pam_syslog(pamh, LOG_INFO,
+    syslog(LOG_INFO,
                "Granting login permission for organization user %s.",
                user_name);
     pam_result = PAM_SUCCESS;
@@ -101,7 +100,7 @@ PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, in
     if (file_exists) {
       remove(users_filename.c_str());
     }
-    pam_syslog(pamh, LOG_INFO,
+    syslog(LOG_INFO,
                "Denying login permission for organization user %s.", user_name);
 
     pam_result = PAM_PERM_DENIED;
