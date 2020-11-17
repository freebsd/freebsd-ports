diff --git src/providers/ldap/ldap_auth.c src/providers/ldap/ldap_auth.c
index de22689ae..fdfd67cf4 100644
--- src/providers/ldap/ldap_auth.c
+++ src/providers/ldap/ldap_auth.c
@@ -37,7 +37,6 @@
 #include <sys/time.h>
 #include <strings.h>
 
-#include <shadow.h>
 #include <security/pam_modules.h>
 
 #include "util/util.h"
@@ -52,6 +51,22 @@
 
 #define LDAP_PWEXPIRE_WARNING_TIME 0
 
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
@@ -97,9 +112,9 @@ static errno_t check_pwexpire_kerberos(const char *expire_date, time_t now,
     }
 
     DEBUG(SSSDBG_TRACE_ALL,
-          "Time info: tzname[0] [%s] tzname[1] [%s] timezone [%ld] "
-           "daylight [%d] now [%ld] expire_time [%ld].\n", tzname[0],
-           tzname[1], timezone, daylight, now, expire_time);
+          "Time info: tzname[0] [%s] tzname[1] [%s] "
+          "now [%ld] expire_time [%ld].\n", tzname[0],
+          tzname[1], now, expire_time);
 
     if (difftime(now, expire_time) > 0.0) {
         DEBUG(SSSDBG_CONF_SETTINGS, "Kerberos password expired.\n");
@@ -946,14 +961,14 @@ sdap_pam_auth_handler_send(TALLOC_CTX *mem_ctx,
 
     state->pd = pd;
     state->be_ctx = params->be_ctx;
-    pd->pam_status = PAM_SYSTEM_ERR;
+    pd->pam_status = PAM_SERVICE_ERR;
 
     switch (pd->cmd) {
     case SSS_PAM_AUTHENTICATE:
         subreq = auth_send(state, params->ev, auth_ctx,
                            pd->user, pd->authtok, false);
         if (subreq == NULL) {
-            pd->pam_status = PAM_SYSTEM_ERR;
+            pd->pam_status = PAM_SERVICE_ERR;
             goto immediately;
         }
 
@@ -963,14 +978,14 @@ sdap_pam_auth_handler_send(TALLOC_CTX *mem_ctx,
         subreq = auth_send(state, params->ev, auth_ctx,
                            pd->user, pd->authtok, true);
         if (subreq == NULL) {
-            pd->pam_status = PAM_SYSTEM_ERR;
+            pd->pam_status = PAM_SERVICE_ERR;
             goto immediately;
         }
 
         tevent_req_set_callback(subreq, sdap_pam_auth_handler_done, req);
         break;
     case SSS_PAM_CHAUTHTOK:
-        pd->pam_status = PAM_SYSTEM_ERR;
+        pd->pam_status = PAM_SERVICE_ERR;
         goto immediately;
 
     case SSS_PAM_ACCT_MGMT:
@@ -1015,7 +1030,7 @@ static void sdap_pam_auth_handler_done(struct tevent_req *subreq)
                                 state->be_ctx->domain->pwd_expiration_warning);
         if (ret == EINVAL) {
             /* Unknown password expiration type. */
-            state->pd->pam_status = PAM_SYSTEM_ERR;
+            state->pd->pam_status = PAM_SERVICE_ERR;
             goto done;
         }
     }
@@ -1049,7 +1064,7 @@ static void sdap_pam_auth_handler_done(struct tevent_req *subreq)
         state->pd->pam_status = PAM_BAD_ITEM;
         break;
     default:
-        state->pd->pam_status = PAM_SYSTEM_ERR;
+        state->pd->pam_status = PAM_SERVICE_ERR;
         break;
     }
 
@@ -1271,7 +1286,7 @@ sdap_pam_chpass_handler_send(TALLOC_CTX *mem_ctx,
     DEBUG(SSSDBG_OP_FAILURE,
           "starting password change request for user [%s].\n", pd->user);
 
-    pd->pam_status = PAM_SYSTEM_ERR;
+    pd->pam_status = PAM_SERVICE_ERR;
 
     if (pd->cmd != SSS_PAM_CHAUTHTOK && pd->cmd != SSS_PAM_CHAUTHTOK_PRELIM) {
         DEBUG(SSSDBG_OP_FAILURE,
@@ -1282,7 +1297,7 @@ sdap_pam_chpass_handler_send(TALLOC_CTX *mem_ctx,
     subreq = auth_send(state, params->ev, auth_ctx,
                        pd->user, pd->authtok, true);
     if (subreq == NULL) {
-        pd->pam_status = PAM_SYSTEM_ERR;
+        pd->pam_status = PAM_SERVICE_ERR;
         goto immediately;
     }
 
@@ -1335,7 +1350,7 @@ static void sdap_pam_chpass_handler_auth_done(struct tevent_req *subreq)
             if (ret == ERR_PASSWORD_EXPIRED) {
                 DEBUG(SSSDBG_CRIT_FAILURE, "LDAP provider cannot change "
                       "kerberos passwords.\n");
-                state->pd->pam_status = PAM_SYSTEM_ERR;
+                state->pd->pam_status = PAM_SERVICE_ERR;
                 goto done;
             }
             break;
@@ -1344,7 +1359,7 @@ static void sdap_pam_chpass_handler_auth_done(struct tevent_req *subreq)
             break;
         default:
             DEBUG(SSSDBG_CRIT_FAILURE, "Unknown password expiration type.\n");
-                state->pd->pam_status = PAM_SYSTEM_ERR;
+                state->pd->pam_status = PAM_SERVICE_ERR;
                 goto done;
         }
     }
@@ -1369,7 +1384,7 @@ static void sdap_pam_chpass_handler_auth_done(struct tevent_req *subreq)
                 if (subreq == NULL) {
                     DEBUG(SSSDBG_OP_FAILURE, "Failed to change password for "
                           "%s\n", state->pd->user);
-                    state->pd->pam_status = PAM_SYSTEM_ERR;
+                    state->pd->pam_status = PAM_SERVICE_ERR;
                     goto done;
                 }
 
@@ -1401,7 +1416,7 @@ static void sdap_pam_chpass_handler_auth_done(struct tevent_req *subreq)
             be_mark_offline(state->be_ctx);
             break;
         default:
-            state->pd->pam_status = PAM_SYSTEM_ERR;
+            state->pd->pam_status = PAM_SERVICE_ERR;
             break;
         }
 
@@ -1437,7 +1452,7 @@ static void sdap_pam_chpass_handler_chpass_done(struct tevent_req *subreq)
         state->pd->pam_status = PAM_AUTHTOK_ERR;
         break;
     default:
-        state->pd->pam_status = PAM_SYSTEM_ERR;
+        state->pd->pam_status = PAM_SERVICE_ERR;
         break;
     }
 
@@ -1463,7 +1478,7 @@ static void sdap_pam_chpass_handler_chpass_done(struct tevent_req *subreq)
                                                     state->sh, state->dn,
                                                     lastchanged_name);
         if (subreq == NULL) {
-            state->pd->pam_status = PAM_SYSTEM_ERR;
+            state->pd->pam_status = PAM_SERVICE_ERR;
             goto done;
         }
 
@@ -1489,7 +1504,7 @@ static void sdap_pam_chpass_handler_last_done(struct tevent_req *subreq)
     talloc_free(subreq);
 
     if (ret != EOK) {
-        state->pd->pam_status = PAM_SYSTEM_ERR;
+        state->pd->pam_status = PAM_SERVICE_ERR;
         goto done;
     }
 
