diff --git src/providers/ldap/sdap_async_users.c src/providers/ldap/sdap_async_users.c
index 92eeda1d3..8847be79b 100644
--- src/providers/ldap/sdap_async_users.c
+++ src/providers/ldap/sdap_async_users.c
@@ -61,7 +61,8 @@ sdap_get_idmap_primary_gid(struct sdap_options *opts,
 {
     errno_t ret;
     TALLOC_CTX *tmpctx = NULL;
-    gid_t gid, primary_gid;
+    id_t gid;
+    gid_t primary_gid;
     char *group_sid_str;
 
     tmpctx = talloc_new(NULL);
@@ -108,7 +109,7 @@ sdap_get_idmap_primary_gid(struct sdap_options *opts,
     if (ret != EOK) goto done;
 
     ret = EOK;
-    *_gid = gid;
+    *_gid = (gid_t) gid;
 done:
     talloc_free(tmpctx);
     return ret;
@@ -188,6 +189,7 @@ int sdap_save_user(TALLOC_CTX *memctx,
     const char *orig_dn = NULL;
     uid_t uid = 0;
     gid_t gid = 0;
+    id_t temp_id;
     struct sysdb_attrs *user_attrs;
     char *upn = NULL;
     size_t i;
@@ -331,7 +333,7 @@ int sdap_save_user(TALLOC_CTX *memctx,
               "Mapping user [%s] objectSID [%s] to unix ID\n", user_name, sid_str);
 
         /* Convert the SID into a UNIX user ID */
-        ret = sdap_idmap_sid_to_unix(opts->idmap_ctx, sid_str, &uid);
+        ret = sdap_idmap_sid_to_unix(opts->idmap_ctx, sid_str, &temp_id);
         if (ret == ENOTSUP) {
             DEBUG(SSSDBG_TRACE_FUNC, "Skipping built-in object.\n");
             ret = EOK;
@@ -339,6 +341,7 @@ int sdap_save_user(TALLOC_CTX *memctx,
         } else if (ret != EOK) {
             goto done;
         }
+        uid = (uid_t) temp_id;
 
         /* Store the UID in the ldap_attrs so it doesn't get
          * treated as a missing attribute from LDAP and removed.
