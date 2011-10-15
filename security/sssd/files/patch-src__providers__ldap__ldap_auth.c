--- ./src/providers/ldap/ldap_auth.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/providers/ldap/ldap_auth.c	2011-10-13 12:15:03.000000000 -0400
@@ -37,7 +37,6 @@
 #include <sys/time.h>
 #include <strings.h>
 
-#include <shadow.h>
 #include <security/pam_modules.h>
 
 #include "util/util.h"
@@ -46,6 +45,7 @@
 #include "providers/ldap/ldap_common.h"
 #include "providers/ldap/sdap_async.h"
 
+
 /* MIT Kerberos has the same hardcoded warning interval of 7 days. Due to the
  * fact that using the expiration time of a Kerberos password with LDAP
  * authentication is presumably a rare case a separate config option is not
@@ -59,6 +59,22 @@
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
@@ -111,17 +127,16 @@
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
@@ -742,7 +757,7 @@
 
     DEBUG(2, ("starting password change request for user [%s].\n", pd->user));
 
-    pd->pam_status = PAM_SYSTEM_ERR;
+    pd->pam_status = PAM_SERVICE_ERR;
 
     if (pd->cmd != SSS_PAM_CHAUTHTOK && pd->cmd != SSS_PAM_CHAUTHTOK_PRELIM) {
         DEBUG(2, ("chpass target was called by wrong pam command.\n"));
@@ -799,7 +814,7 @@
                     &pw_expire_type, &pw_expire_data);
     talloc_zfree(req);
     if (ret) {
-        state->pd->pam_status = PAM_SYSTEM_ERR;
+        state->pd->pam_status = PAM_SERVICE_ERR;
         goto done;
     }
 
@@ -819,7 +834,7 @@
                                             &result);
                 if (ret != EOK) {
                     DEBUG(1, ("check_pwexpire_shadow failed.\n"));
-                    state->pd->pam_status = PAM_SYSTEM_ERR;
+                    state->pd->pam_status = PAM_SERVICE_ERR;
                     goto done;
                 }
                 break;
@@ -828,14 +843,14 @@
                                               &result);
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
@@ -844,7 +859,7 @@
                 break;
             default:
                 DEBUG(1, ("Unknow pasword expiration type.\n"));
-                    state->pd->pam_status = PAM_SYSTEM_ERR;
+                    state->pd->pam_status = PAM_SERVICE_ERR;
                     goto done;
         }
     }
@@ -884,7 +899,7 @@
         dp_err = DP_ERR_OFFLINE;
         break;
     default:
-        state->pd->pam_status = PAM_SYSTEM_ERR;
+        state->pd->pam_status = PAM_SERVICE_ERR;
     }
 
 done:
@@ -905,7 +920,7 @@
     ret = sdap_exop_modify_passwd_recv(req, state, &result, &user_error_message);
     talloc_zfree(req);
     if (ret) {
-        state->pd->pam_status = PAM_SYSTEM_ERR;
+        state->pd->pam_status = PAM_SERVICE_ERR;
         goto done;
     }
 
@@ -964,7 +979,7 @@
         goto done;
     }
 
-    pd->pam_status = PAM_SYSTEM_ERR;
+    pd->pam_status = PAM_SERVICE_ERR;
 
     switch (pd->cmd) {
     case SSS_PAM_AUTHENTICATE:
@@ -1021,7 +1036,7 @@
                     &pw_expire_type, &pw_expire_data);
     talloc_zfree(req);
     if (ret != EOK) {
-        state->pd->pam_status = PAM_SYSTEM_ERR;
+        state->pd->pam_status = PAM_SERVICE_ERR;
         dp_err = DP_ERR_FATAL;
         goto done;
     }
@@ -1033,7 +1048,7 @@
                                             state->pd, &result);
                 if (ret != EOK) {
                     DEBUG(1, ("check_pwexpire_shadow failed.\n"));
-                    state->pd->pam_status = PAM_SYSTEM_ERR;
+                    state->pd->pam_status = PAM_SERVICE_ERR;
                     goto done;
                 }
                 break;
@@ -1042,7 +1057,7 @@
                                               state->pd, &result);
                 if (ret != EOK) {
                     DEBUG(1, ("check_pwexpire_kerberos failed.\n"));
-                    state->pd->pam_status = PAM_SYSTEM_ERR;
+                    state->pd->pam_status = PAM_SERVICE_ERR;
                     goto done;
                 }
                 break;
@@ -1050,7 +1065,7 @@
                 ret = check_pwexpire_ldap(state->pd, pw_expire_data, &result);
                 if (ret != EOK) {
                     DEBUG(1, ("check_pwexpire_ldap failed.\n"));
-                    state->pd->pam_status = PAM_SYSTEM_ERR;
+                    state->pd->pam_status = PAM_SERVICE_ERR;
                     goto done;
                 }
                 break;
@@ -1058,7 +1073,7 @@
                 break;
             default:
                 DEBUG(1, ("Unknow pasword expiration type.\n"));
-                    state->pd->pam_status = PAM_SYSTEM_ERR;
+                    state->pd->pam_status = PAM_SERVICE_ERR;
                     goto done;
         }
     }
@@ -1080,7 +1095,7 @@
         state->pd->pam_status = PAM_NEW_AUTHTOK_REQD;
         break;
     default:
-        state->pd->pam_status = PAM_SYSTEM_ERR;
+        state->pd->pam_status = PAM_SERVICE_ERR;
         dp_err = DP_ERR_FATAL;
     }
 
