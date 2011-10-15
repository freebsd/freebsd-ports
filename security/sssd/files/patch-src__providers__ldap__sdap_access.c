--- ./src/providers/ldap/sdap_access.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/providers/ldap/sdap_access.c	2011-10-13 12:15:03.000000000 -0400
@@ -22,9 +22,7 @@
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
-#define _XOPEN_SOURCE 500 /* for strptime() */
 #include <time.h>
-#undef _XOPEN_SOURCE
 #include <sys/param.h>
 #include <security/pam_modules.h>
 #include <talloc.h>
@@ -119,7 +117,7 @@
                            pd);
     if (req == NULL) {
         DEBUG(1, ("Unable to start sdap_access request\n"));
-        sdap_access_reply(breq, PAM_SYSTEM_ERR);
+        sdap_access_reply(breq, PAM_SERVICE_ERR);
         return;
     }
 
@@ -157,7 +155,7 @@
 
     state->be_ctx = be_ctx;
     state->pd = pd;
-    state->pam_status = PAM_SYSTEM_ERR;
+    state->pam_status = PAM_SERVICE_ERR;
     state->ev = ev;
     state->access_ctx = access_ctx;
     state->current_rule = 0;
@@ -502,18 +500,17 @@
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
@@ -663,7 +660,7 @@
         return NULL;
     }
 
-    state->pam_status = PAM_SYSTEM_ERR;
+    state->pam_status = PAM_SERVICE_ERR;
 
     expire = dp_opt_get_cstring(access_ctx->id_ctx->opts->basic,
                                 SDAP_ACCOUNT_EXPIRE_POLICY);
@@ -747,7 +744,7 @@
     talloc_zfree(subreq);
     if (ret != EOK) {
         DEBUG(1, ("Error retrieving access check result.\n"));
-        state->pam_status = PAM_SYSTEM_ERR;
+        state->pam_status = PAM_SERVICE_ERR;
         tevent_req_error(req, ret);
         return;
     }
@@ -807,7 +804,7 @@
     state->filter = NULL;
     state->be_ctx = be_ctx;
     state->username = username;
-    state->pam_status = PAM_SYSTEM_ERR;
+    state->pam_status = PAM_SERVICE_ERR;
     state->sdap_ctx = access_ctx->id_ctx;
     state->ev = ev;
     state->access_ctx = access_ctx;
@@ -953,7 +950,7 @@
                                                   SDAP_SEARCH_TIMEOUT));
     if (subreq == NULL) {
         DEBUG(1, ("Could not start LDAP communication\n"));
-        state->pam_status = PAM_SYSTEM_ERR;
+        state->pam_status = PAM_SERVICE_ERR;
         tevent_req_error(req, EIO);
         return;
     }
@@ -984,13 +981,13 @@
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
@@ -1009,7 +1006,7 @@
     else if (results == NULL) {
         DEBUG(1, ("num_results > 0, but results is NULL\n"));
         ret = EIO;
-        state->pam_status = PAM_SYSTEM_ERR;
+        state->pam_status = PAM_SERVICE_ERR;
         goto done;
     }
     else if (num_results > 1) {
@@ -1018,7 +1015,7 @@
          */
         DEBUG(1, ("Received multiple replies\n"));
         ret = EIO;
-        state->pam_status = PAM_SYSTEM_ERR;
+        state->pam_status = PAM_SERVICE_ERR;
         goto done;
     }
     else { /* Ok, we got a single reply */
@@ -1106,7 +1103,7 @@
     talloc_zfree(subreq);
     if (ret != EOK) {
         DEBUG(1, ("Error retrieving access check result.\n"));
-        state->pam_status = PAM_SYSTEM_ERR;
+        state->pam_status = PAM_SERVICE_ERR;
         tevent_req_error(req, ret);
         return;
     }
@@ -1247,7 +1244,7 @@
     talloc_zfree(subreq);
     if (ret != EOK) {
         DEBUG(1, ("Error retrieving access check result.\n"));
-        state->pam_status = PAM_SYSTEM_ERR;
+        state->pam_status = PAM_SERVICE_ERR;
         tevent_req_error(req, ret);
         return;
     }
@@ -1274,7 +1271,7 @@
     struct ldb_message_element *el;
     unsigned int i;
     char *host;
-    char hostname[HOST_NAME_MAX+1];
+    char hostname[_POSIX_HOST_NAME_MAX+1];
 
     req = tevent_req_create(mem_ctx, &state, struct sdap_access_host_ctx);
     if (!req) {
@@ -1370,7 +1367,7 @@
     talloc_zfree(subreq);
     if (ret != EOK) {
         DEBUG(1, ("Error retrieving access check result.\n"));
-        state->pam_status = PAM_SYSTEM_ERR;
+        state->pam_status = PAM_SERVICE_ERR;
         tevent_req_error(req, ret);
         return;
     }
@@ -1395,7 +1392,7 @@
 static void sdap_access_done(struct tevent_req *req)
 {
     errno_t ret;
-    int pam_status = PAM_SYSTEM_ERR;
+    int pam_status = PAM_SERVICE_ERR;
     struct be_req *breq =
             tevent_req_callback_data(req, struct be_req);
 
@@ -1403,7 +1400,7 @@
     talloc_zfree(req);
     if (ret != EOK) {
         DEBUG(1, ("Error retrieving access check result.\n"));
-        pam_status = PAM_SYSTEM_ERR;
+        pam_status = PAM_SERVICE_ERR;
     }
 
     sdap_access_reply(breq, pam_status);
