diff --git src/providers/ldap/sdap_async_initgroups_ad.c src/providers/ldap/sdap_async_initgroups_ad.c
index 3c58f5bc4..7e0a5169d 100644
--- src/providers/ldap/sdap_async_initgroups_ad.c
+++ src/providers/ldap/sdap_async_initgroups_ad.c
@@ -851,6 +851,7 @@ errno_t sdap_ad_save_group_membership_with_idmapping(const char *username,
     size_t i;
     time_t now;
     gid_t gid;
+    id_t temp_id;
     char **groups = NULL;
     size_t num_groups;
     errno_t ret;
@@ -881,7 +882,8 @@ errno_t sdap_ad_save_group_membership_with_idmapping(const char *username,
         sid = sids[i];
         DEBUG(SSSDBG_TRACE_LIBS, "Processing membership SID [%s]\n", sid);
 
-        ret = sdap_idmap_sid_to_unix(idmap_ctx, sid, &gid);
+        ret = sdap_idmap_sid_to_unix(idmap_ctx, sid, &temp_id);
+        gid = (gid_t) temp_id;
         if (ret == ENOTSUP) {
             DEBUG(SSSDBG_TRACE_FUNC, "Skipping built-in object.\n");
             continue;
