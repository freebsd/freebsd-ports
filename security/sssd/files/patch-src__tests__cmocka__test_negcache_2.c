--- src/tests/cmocka/test_negcache_2.c.orig	2020-03-17 13:31:28 UTC
+++ src/tests/cmocka/test_negcache_2.c
@@ -115,14 +115,10 @@ static void find_local_users(struct ncache_test_ctx *t
 static void find_local_users(struct ncache_test_ctx *test_ctx)
 {
     int i;
-    FILE *passwd_file;
     const struct passwd *pwd;
 
-    passwd_file = fopen("/etc/passwd", "r");
-    assert_non_null(passwd_file);
-
     for (i = 0; i < 2; /*no-op*/) {
-        pwd = fgetpwent(passwd_file);
+        pwd = getpwent();
         assert_non_null(pwd);
         if (pwd->pw_uid == 0) {
             /* skip root */
@@ -134,20 +130,15 @@ static void find_local_users(struct ncache_test_ctx *t
         ++i;
     }
 
-    fclose(passwd_file);
 }
 
 static void find_local_groups(struct ncache_test_ctx *test_ctx)
 {
     int i;
-    FILE *group_file;
     const struct group *grp;
 
-    group_file = fopen("/etc/group", "r");
-    assert_non_null(group_file);
-
     for (i = 0; i < 2; /* no-op */) {
-        grp = fgetgrent(group_file);
+        grp = getgrent();
         assert_non_null(grp);
         if (grp->gr_gid == 0) {
             /* skip root */
@@ -159,7 +150,6 @@ static void find_local_groups(struct ncache_test_ctx *
         ++i;
     }
 
-    fclose(group_file);
 }
 
 static void find_non_local_users(struct ncache_test_ctx *test_ctx)
