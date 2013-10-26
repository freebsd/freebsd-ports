From ad4b85556ddea5d5d2d6bcc5f00a8492b0b15c46 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:11 +0200
Subject: [PATCH 09/34] patch-src__providers__ldap__ldap_auth.c

---
 src/providers/ldap/ldap_auth.c | 60 ++++++++++++++++++++++++++----------------
 1 file changed, 37 insertions(+), 23 deletions(-)

diff --git src/providers/ldap/ldap_auth.c src/providers/ldap/ldap_auth.c
index b0dd30c..6b1ad83 100644
--- src/providers/ldap/ldap_auth.c
+++ src/providers/ldap/ldap_auth.c
@@ -37,7 +37,6 @@
 #include <sys/time.h>
 #include <strings.h>
 
-#include <shadow.h>
 #include <security/pam_modules.h>
 
 #include "util/util.h"
@@ -56,6 +55,22 @@ enum pwexpire {
     PWEXPIRE_SHADOW
 };
 
+struct spwd
+{
+  char *sp_namp;              /* Login name.  */
+  char *sp_pwdp;              /* Encrypted password.  */
+  long int sp_lstchg;         /* Date of last change.  */
+  long int sp_min;            /* Minimum number of days between changes.  */
+  long int sp_max;            /* Maximum number of days between changes.  */
+  long int sp_warn;           /* Number of days to warn user to change
+				 the password.  */
+  long int sp_inact;          /* Number of days the account may be
+				 inactive.  */
+  long int sp_expire;         /* Number of days since 1970-01-01 until
+				 account expires.  */
+  unsigned long int sp_flag;  /* Reserved.  */
+};
+
 static errno_t add_expired_warning(struct pam_data *pd, long exp_time)
 {
     int ret;
@@ -110,17 +125,16 @@ static errno_t check_pwexpire_kerberos(const char *expire_date, time_t now,
         return EINVAL;
     }
 
+    tzset();
     expire_time = mktime(&tm);
     if (expire_time == -1) {
         DEBUG(1, ("mktime failed to convert [%s].\n", expire_date));
         return EINVAL;
     }
 
-    tzset();
-    expire_time -= timezone;
-    DEBUG(9, ("Time info: tzname[0] [%s] tzname[1] [%s] timezone [%d] "
-              "daylight [%d] now [%d] expire_time [%d].\n", tzname[0],
-              tzname[1], timezone, daylight, now, expire_time));
+    DEBUG(9, ("Time info: tzname[0] [%s] tzname[1] [%s]"
+              "now [%d] expire_time [%d].\n", tzname[0],
+              tzname[1], now, expire_time));
 
     if (difftime(now, expire_time) > 0.0) {
         DEBUG(4, ("Kerberos password expired.\n"));
@@ -762,7 +776,7 @@ void sdap_pam_chpass_handler(struct be_req *breq)
 
     DEBUG(2, ("starting password change request for user [%s].\n", pd->user));
 
-    pd->pam_status = PAM_SYSTEM_ERR;
+    pd->pam_status = PAM_SERVICE_ERR;
 
     if (pd->cmd != SSS_PAM_CHAUTHTOK && pd->cmd != SSS_PAM_CHAUTHTOK_PRELIM) {
         DEBUG(2, ("chpass target was called by wrong pam command.\n"));
@@ -821,7 +835,7 @@ static void sdap_auth4chpass_done(struct tevent_req *req)
                     &pw_expire_type, &pw_expire_data);
     talloc_zfree(req);
     if (ret) {
-        state->pd->pam_status = PAM_SYSTEM_ERR;
+        state->pd->pam_status = PAM_SERVICE_ERR;
         goto done;
     }
 
@@ -841,7 +855,7 @@ static void sdap_auth4chpass_done(struct tevent_req *req)
                                             &result);
                 if (ret != EOK) {
                     DEBUG(1, ("check_pwexpire_shadow failed.\n"));
-                    state->pd->pam_status = PAM_SYSTEM_ERR;
+                    state->pd->pam_status = PAM_SERVICE_ERR;
                     goto done;
                 }
                 break;
@@ -850,14 +864,14 @@ static void sdap_auth4chpass_done(struct tevent_req *req)
                                               state->breq->domain->pwd_expiration_warning);
                 if (ret != EOK) {
                     DEBUG(1, ("check_pwexpire_kerberos failed.\n"));
-                    state->pd->pam_status = PAM_SYSTEM_ERR;
+                    state->pd->pam_status = PAM_SERVICE_ERR;
                     goto done;
                 }
 
                 if (result == SDAP_AUTH_PW_EXPIRED) {
                     DEBUG(1, ("LDAP provider cannot change kerberos "
                               "passwords.\n"));
-                    state->pd->pam_status = PAM_SYSTEM_ERR;
+                    state->pd->pam_status = PAM_SERVICE_ERR;
                     goto done;
                 }
                 break;
@@ -866,7 +880,7 @@ static void sdap_auth4chpass_done(struct tevent_req *req)
                 break;
             default:
                 DEBUG(1, ("Unknow pasword expiration type.\n"));
-                    state->pd->pam_status = PAM_SYSTEM_ERR;
+                    state->pd->pam_status = PAM_SERVICE_ERR;
                     goto done;
         }
     }
@@ -906,7 +920,7 @@ static void sdap_auth4chpass_done(struct tevent_req *req)
         dp_err = DP_ERR_OFFLINE;
         break;
     default:
-        state->pd->pam_status = PAM_SYSTEM_ERR;
+        state->pd->pam_status = PAM_SERVICE_ERR;
     }
 
 done:
@@ -929,7 +943,7 @@ static void sdap_pam_chpass_done(struct tevent_req *req)
     ret = sdap_exop_modify_passwd_recv(req, state, &result, &user_error_message);
     talloc_zfree(req);
     if (ret && ret != EIO) {
-        state->pd->pam_status = PAM_SYSTEM_ERR;
+        state->pd->pam_status = PAM_SERVICE_ERR;
         goto done;
     }
 
@@ -970,7 +984,7 @@ static void sdap_pam_chpass_done(struct tevent_req *req)
                                               state->dn,
                                               lastchanged_name);
         if (subreq == NULL) {
-            state->pd->pam_status = PAM_SYSTEM_ERR;
+            state->pd->pam_status = PAM_SERVICE_ERR;
             goto done;
         }
 
@@ -991,7 +1005,7 @@ static void sdap_lastchange_done(struct tevent_req *req)
 
     ret = sdap_modify_shadow_lastchange_recv(req);
     if (ret != EOK) {
-        state->pd->pam_status = PAM_SYSTEM_ERR;
+        state->pd->pam_status = PAM_SERVICE_ERR;
         goto done;
     }
 
@@ -1032,7 +1046,7 @@ void sdap_pam_auth_handler(struct be_req *breq)
         goto done;
     }
 
-    pd->pam_status = PAM_SYSTEM_ERR;
+    pd->pam_status = PAM_SERVICE_ERR;
 
     switch (pd->cmd) {
     case SSS_PAM_AUTHENTICATE:
@@ -1090,7 +1104,7 @@ static void sdap_pam_auth_done(struct tevent_req *req)
                     &pw_expire_type, &pw_expire_data);
     talloc_zfree(req);
     if (ret != EOK) {
-        state->pd->pam_status = PAM_SYSTEM_ERR;
+        state->pd->pam_status = PAM_SERVICE_ERR;
         dp_err = DP_ERR_FATAL;
         goto done;
     }
@@ -1102,7 +1116,7 @@ static void sdap_pam_auth_done(struct tevent_req *req)
                                             state->pd, &result);
                 if (ret != EOK) {
                     DEBUG(1, ("check_pwexpire_shadow failed.\n"));
-                    state->pd->pam_status = PAM_SYSTEM_ERR;
+                    state->pd->pam_status = PAM_SERVICE_ERR;
                     goto done;
                 }
                 break;
@@ -1112,7 +1126,7 @@ static void sdap_pam_auth_done(struct tevent_req *req)
                                               be_ctx->domain->pwd_expiration_warning);
                 if (ret != EOK) {
                     DEBUG(1, ("check_pwexpire_kerberos failed.\n"));
-                    state->pd->pam_status = PAM_SYSTEM_ERR;
+                    state->pd->pam_status = PAM_SERVICE_ERR;
                     goto done;
                 }
                 break;
@@ -1121,7 +1135,7 @@ static void sdap_pam_auth_done(struct tevent_req *req)
                                           be_ctx->domain->pwd_expiration_warning);
                 if (ret != EOK) {
                     DEBUG(1, ("check_pwexpire_ldap failed.\n"));
-                    state->pd->pam_status = PAM_SYSTEM_ERR;
+                    state->pd->pam_status = PAM_SERVICE_ERR;
                     goto done;
                 }
                 break;
@@ -1129,7 +1143,7 @@ static void sdap_pam_auth_done(struct tevent_req *req)
                 break;
             default:
                 DEBUG(1, ("Unknow pasword expiration type.\n"));
-                    state->pd->pam_status = PAM_SYSTEM_ERR;
+                    state->pd->pam_status = PAM_SERVICE_ERR;
                     goto done;
         }
     }
@@ -1151,7 +1165,7 @@ static void sdap_pam_auth_done(struct tevent_req *req)
         state->pd->pam_status = PAM_NEW_AUTHTOK_REQD;
         break;
     default:
-        state->pd->pam_status = PAM_SYSTEM_ERR;
+        state->pd->pam_status = PAM_SERVICE_ERR;
         dp_err = DP_ERR_FATAL;
     }
 
-- 
1.8.0

