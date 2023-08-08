--- src/util.c.orig	2019-04-23 15:16:09 UTC
+++ src/util.c
@@ -254,7 +254,7 @@ get_user_groups (const gchar  *user,
         *groups = g_new (gid_t, ngroups);
         res = getgrouplist (user, group, *groups, &ngroups);
 
-        return res;
+        return res == 0 ? ngroups : res;
 }
 
 
