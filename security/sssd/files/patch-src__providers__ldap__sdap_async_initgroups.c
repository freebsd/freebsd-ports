--- src/providers/ldap/sdap_async_initgroups.c.orig	2020-03-17 13:31:28 UTC
+++ src/providers/ldap/sdap_async_initgroups.c
@@ -45,6 +45,7 @@ errno_t sdap_add_incomplete_groups(struct sysdb_ctx *s
     const char *uuid = NULL;
     char **missing;
     gid_t gid;
+    id_t temp_id;
     int ret;
     errno_t sret;
     bool in_transaction = false;
@@ -146,7 +147,8 @@ errno_t sdap_add_incomplete_groups(struct sysdb_ctx *s
 
                     /* Convert the SID into a UNIX group ID */
                     ret = sdap_idmap_sid_to_unix(opts->idmap_ctx, sid_str,
-                                                 &gid);
+                                                 &temp_id);
+                    gid = (gid_t) temp_id;
                     if (ret == EOK) {
                         DEBUG(SSSDBG_TRACE_INTERNAL,
                               "Group [%s] has mapped gid [%lu]\n",
@@ -3305,6 +3307,7 @@ static void sdap_get_initgr_done(struct tevent_req *su
     int ret;
     TALLOC_CTX *tmp_ctx;
     gid_t primary_gid;
+    id_t temp_id;
     char *gid;
     char *sid_str;
     char *dom_sid_str;
@@ -3411,8 +3414,9 @@ static void sdap_get_initgr_done(struct tevent_req *su
 
         /* Convert the SID into a UNIX group ID */
         ret = sdap_idmap_sid_to_unix(opts->idmap_ctx, group_sid_str,
-                                     &primary_gid);
+                                     &temp_id);
         if (ret != EOK) goto done;
+        primary_gid = (gid_t) temp_id;
     } else {
         ret = sysdb_attrs_get_uint32_t(state->orig_user, SYSDB_GIDNUM,
                                        &primary_gid);
