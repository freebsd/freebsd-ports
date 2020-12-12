diff --git src/providers/ldap/sdap_async_groups.c src/providers/ldap/sdap_async_groups.c
index 09e15bc3d..c74e4c3ea 100644
--- src/providers/ldap/sdap_async_groups.c
+++ src/providers/ldap/sdap_async_groups.c
@@ -505,6 +505,7 @@ static int sdap_save_group(TALLOC_CTX *memctx,
     struct sysdb_attrs *group_attrs;
     const char *group_name = NULL;
     gid_t gid;
+    id_t temp_id;
     errno_t ret;
     char *usn_value = NULL;
     TALLOC_CTX *tmpctx = NULL;
@@ -615,7 +616,8 @@ static int sdap_save_group(TALLOC_CTX *memctx,
                    group_name, sid_str);
 
             /* Convert the SID into a UNIX group ID */
-            ret = sdap_idmap_sid_to_unix(opts->idmap_ctx, sid_str, &gid);
+            ret = sdap_idmap_sid_to_unix(opts->idmap_ctx, sid_str, &temp_id);
+            gid = (gid_t) temp_id;
             if (ret == ENOTSUP) {
                 /* ENOTSUP is returned if built-in SID was provided
                  * => do not store the group, but return EOK */
