From cebca2806d06fce5a5c610a39044a5a4039f71ef Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:11 +0200
Subject: [PATCH 12/34] patch-src__providers__ldap__sdap_access.c

---
 src/providers/ldap/sdap_access.c | 43 +++++++++++++++++++---------------------
 1 file changed, 20 insertions(+), 23 deletions(-)

diff --git src/providers/ldap/sdap_access.c src/providers/ldap/sdap_access.c
index b198e04..37eae45 100644
--- src/providers/ldap/sdap_access.c
+++ src/providers/ldap/sdap_access.c
@@ -22,9 +22,7 @@
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
-#define _XOPEN_SOURCE 500 /* for strptime() */
 #include <time.h>
-#undef _XOPEN_SOURCE
 #include <sys/param.h>
 #include <security/pam_modules.h>
 #include <talloc.h>
@@ -109,7 +107,7 @@ void sdap_pam_access_handler(struct be_req *breq)
                            pd);
     if (req == NULL) {
         DEBUG(1, ("Unable to start sdap_access request\n"));
-        sdap_access_reply(breq, PAM_SYSTEM_ERR);
+        sdap_access_reply(breq, PAM_SERVICE_ERR);
         return;
     }
 
@@ -149,7 +147,7 @@ sdap_access_send(TALLOC_CTX *mem_ctx,
 
     state->be_req = be_req;
     state->pd = pd;
-    state->pam_status = PAM_SYSTEM_ERR;
+    state->pam_status = PAM_SERVICE_ERR;
     state->ev = ev;
     state->access_ctx = access_ctx;
     state->current_rule = 0;
@@ -502,18 +500,17 @@ static bool nds_check_expired(const char *exp_time_str)
         return true;
     }
 
+    tzset();
     expire_time = mktime(&tm);
     if (expire_time == -1) {
         DEBUG(1, ("mktime failed to convert [%s].\n", exp_time_str));
         return true;
     }
 
-    tzset();
-    expire_time -= timezone;
     now = time(NULL);
-    DEBUG(9, ("Time info: tzname[0] [%s] tzname[1] [%s] timezone [%d] "
-              "daylight [%d] now [%d] expire_time [%d].\n", tzname[0],
-              tzname[1], timezone, daylight, now, expire_time));
+    DEBUG(9, ("Time info: tzname[0] [%s] tzname[1] [%s] "
+              "now [%d] expire_time [%d].\n", tzname[0],
+              tzname[1], now, expire_time));
 
     if (difftime(now, expire_time) > 0.0) {
         DEBUG(4, ("NDS account expired.\n"));
@@ -662,7 +659,7 @@ static struct tevent_req *sdap_account_expired_send(TALLOC_CTX *mem_ctx,
         return NULL;
     }
 
-    state->pam_status = PAM_SYSTEM_ERR;
+    state->pam_status = PAM_SERVICE_ERR;
 
     expire = dp_opt_get_cstring(access_ctx->id_ctx->opts->basic,
                                 SDAP_ACCOUNT_EXPIRE_POLICY);
@@ -746,7 +743,7 @@ static void sdap_account_expired_done(struct tevent_req *subreq)
     talloc_zfree(subreq);
     if (ret != EOK) {
         DEBUG(1, ("Error retrieving access check result.\n"));
-        state->pam_status = PAM_SYSTEM_ERR;
+        state->pam_status = PAM_SERVICE_ERR;
         tevent_req_error(req, ret);
         return;
     }
@@ -806,7 +803,7 @@ static struct tevent_req *sdap_access_filter_send(TALLOC_CTX *mem_ctx,
     state->filter = NULL;
     state->be_req = be_req;
     state->username = username;
-    state->pam_status = PAM_SYSTEM_ERR;
+    state->pam_status = PAM_SERVICE_ERR;
     state->sdap_ctx = access_ctx->id_ctx;
     state->ev = ev;
     state->access_ctx = access_ctx;
@@ -953,7 +950,7 @@ static void sdap_access_filter_connect_done(struct tevent_req *subreq)
                                    false);
     if (subreq == NULL) {
         DEBUG(1, ("Could not start LDAP communication\n"));
-        state->pam_status = PAM_SYSTEM_ERR;
+        state->pam_status = PAM_SERVICE_ERR;
         tevent_req_error(req, EIO);
         return;
     }
@@ -984,13 +981,13 @@ static void sdap_access_filter_get_access_done(struct tevent_req *subreq)
             if (ret == EOK) {
                 return;
             }
-            state->pam_status = PAM_SYSTEM_ERR;
+            state->pam_status = PAM_SERVICE_ERR;
         } else if (dp_error == DP_ERR_OFFLINE) {
             sdap_access_filter_decide_offline(req);
         } else {
             DEBUG(1, ("sdap_get_generic_send() returned error [%d][%s]\n",
                       ret, strerror(ret)));
-            state->pam_status = PAM_SYSTEM_ERR;
+            state->pam_status = PAM_SERVICE_ERR;
         }
 
         goto done;
@@ -1009,7 +1006,7 @@ static void sdap_access_filter_get_access_done(struct tevent_req *subreq)
     else if (results == NULL) {
         DEBUG(1, ("num_results > 0, but results is NULL\n"));
         ret = EIO;
-        state->pam_status = PAM_SYSTEM_ERR;
+        state->pam_status = PAM_SERVICE_ERR;
         goto done;
     }
     else if (num_results > 1) {
@@ -1018,7 +1015,7 @@ static void sdap_access_filter_get_access_done(struct tevent_req *subreq)
          */
         DEBUG(1, ("Received multiple replies\n"));
         ret = EIO;
-        state->pam_status = PAM_SYSTEM_ERR;
+        state->pam_status = PAM_SERVICE_ERR;
         goto done;
     }
     else { /* Ok, we got a single reply */
@@ -1104,7 +1101,7 @@ static void sdap_access_filter_done(struct tevent_req *subreq)
     talloc_zfree(subreq);
     if (ret != EOK) {
         DEBUG(1, ("Error retrieving access check result.\n"));
-        state->pam_status = PAM_SYSTEM_ERR;
+        state->pam_status = PAM_SERVICE_ERR;
         tevent_req_error(req, ret);
         return;
     }
@@ -1244,7 +1241,7 @@ static void sdap_access_service_done(struct tevent_req *subreq)
     talloc_zfree(subreq);
     if (ret != EOK) {
         DEBUG(1, ("Error retrieving access check result.\n"));
-        state->pam_status = PAM_SYSTEM_ERR;
+        state->pam_status = PAM_SERVICE_ERR;
         tevent_req_error(req, ret);
         return;
     }
@@ -1269,7 +1266,7 @@ static struct tevent_req *sdap_access_host_send(
     struct ldb_message_element *el;
     unsigned int i;
     char *host;
-    char hostname[HOST_NAME_MAX+1];
+    char hostname[_POSIX_HOST_NAME_MAX+1];
 
     req = tevent_req_create(mem_ctx, &state, struct sdap_access_host_ctx);
     if (!req) {
@@ -1365,7 +1362,7 @@ static void sdap_access_host_done(struct tevent_req *subreq)
     talloc_zfree(subreq);
     if (ret != EOK) {
         DEBUG(1, ("Error retrieving access check result.\n"));
-        state->pam_status = PAM_SYSTEM_ERR;
+        state->pam_status = PAM_SERVICE_ERR;
         tevent_req_error(req, ret);
         return;
     }
@@ -1391,7 +1388,7 @@ sdap_access_recv(struct tevent_req *req, int *pam_status)
 static void sdap_access_done(struct tevent_req *req)
 {
     errno_t ret;
-    int pam_status = PAM_SYSTEM_ERR;
+    int pam_status = PAM_SERVICE_ERR;
     struct be_req *breq =
             tevent_req_callback_data(req, struct be_req);
 
@@ -1399,7 +1396,7 @@ static void sdap_access_done(struct tevent_req *req)
     talloc_zfree(req);
     if (ret != EOK) {
         DEBUG(1, ("Error retrieving access check result.\n"));
-        pam_status = PAM_SYSTEM_ERR;
+        pam_status = PAM_SERVICE_ERR;
     }
 
     sdap_access_reply(breq, pam_status);
-- 
1.8.0

