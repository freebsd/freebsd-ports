--- pam_module/pam_oslogin_login.cc.orig	2019-02-20 12:34:55 UTC
+++ pam_module/pam_oslogin_login.cc
@@ -14,7 +14,6 @@
 
 #define PAM_SM_ACCOUNT
 #include <security/pam_appl.h>
-#include <security/pam_ext.h>
 #include <security/pam_modules.h>
 #include <sys/stat.h>
 #include <sys/types.h>
@@ -53,7 +52,7 @@ PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, in
   int pam_result = PAM_PERM_DENIED;
   const char *user_name;
   if ((pam_result = pam_get_user(pamh, &user_name, NULL)) != PAM_SUCCESS) {
-    pam_syslog(pamh, LOG_INFO, "Could not get pam user.");
+    syslog(LOG_INFO, "Could not get pam user.");
     return pam_result;
   }
   string str_user_name(user_name);
@@ -100,7 +99,7 @@ PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, in
       chown(users_filename.c_str(), 0, 0);
       chmod(users_filename.c_str(), S_IRUSR | S_IWUSR | S_IRGRP);
     }
-    pam_syslog(pamh, LOG_INFO,
+    syslog(LOG_INFO,
                "Granting login permission for organization user %s.",
                user_name);
     pam_result = PAM_SUCCESS;
@@ -108,7 +107,7 @@ PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, in
     if (file_exists) {
       remove(users_filename.c_str());
     }
-    pam_syslog(pamh, LOG_INFO,
+    syslog(LOG_INFO,
                "Denying login permission for organization user %s.",
                user_name);
 
@@ -128,7 +127,7 @@ PAM_EXTERN int pam_sm_authenticate(pam_handle_t * pamh
 {
   const char* user_name;
   if (pam_get_user(pamh, &user_name, NULL) != PAM_SUCCESS) {
-    pam_syslog(pamh, LOG_INFO, "Could not get pam user.");
+    syslog(LOG_INFO, "Could not get pam user.");
     return PAM_PERM_DENIED;
   }
 
@@ -155,7 +154,7 @@ PAM_EXTERN int pam_sm_authenticate(pam_handle_t * pamh
 
   response = "";
   if (!StartSession(email, &response)) {
-    pam_syslog(pamh, LOG_ERR,
+    syslog(LOG_ERR,
                "Bad response from the two-factor start session request: %s",
                response.empty() ? "empty response" : response.c_str());
     return PAM_PERM_DENIED;
@@ -163,7 +162,7 @@ PAM_EXTERN int pam_sm_authenticate(pam_handle_t * pamh
 
   string status;
   if (!ParseJsonToKey(response, "status", &status)) {
-    pam_syslog(pamh, LOG_ERR,
+    syslog(LOG_ERR,
                "Failed to parse status from start session response");
     return PAM_PERM_DENIED;
   }
@@ -179,7 +178,7 @@ PAM_EXTERN int pam_sm_authenticate(pam_handle_t * pamh
 
   std::vector<oslogin_utils::Challenge> challenges;
   if (!ParseJsonToChallenges(response, &challenges)) {
-    pam_syslog(pamh, LOG_ERR,
+    syslog(LOG_ERR,
                "Failed to parse challenge values from JSON response");
     return PAM_PERM_DENIED;
   }
@@ -242,13 +241,13 @@ PAM_EXTERN int pam_sm_authenticate(pam_handle_t * pamh
       pam_error(pamh, "Unable to get user input");
     }
   } else {
-    pam_syslog(pamh, LOG_ERR, "Unsupported challenge type %s",
+    syslog(LOG_ERR, "Unsupported challenge type %s",
                challenge.type.c_str());
     return PAM_PERM_DENIED;
   }
 
   if (!ContinueSession(email, user_token, session_id, challenge, &response)) {
-      pam_syslog(pamh, LOG_ERR,
+      syslog(LOG_ERR,
                  "Bad response from two-factor continue session request: %s",
                  response.empty() ? "empty response" : response.c_str());
       return PAM_PERM_DENIED;
