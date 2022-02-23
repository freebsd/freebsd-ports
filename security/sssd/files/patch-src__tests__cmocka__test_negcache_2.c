--- src/tests/cmocka/test_negcache_2.c	2020-03-17 09:31:28.000000000 -0400
+++ src/tests/cmocka/test_negcache_2.c	2022-02-22 23:48:57.315866000 -0500
@@ -116,12 +116,8 @@
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
@@ -135,5 +131,4 @@
     }
 
-    fclose(passwd_file);
 }
 
@@ -141,12 +136,8 @@
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
@@ -160,5 +151,4 @@
     }
 
-    fclose(group_file);
 }
 
