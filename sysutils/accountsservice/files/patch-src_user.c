--- src/user.c.orig	2014-03-15 15:16:49.000000000 +0100
+++ src/user.c	2014-03-15 15:31:57.000000000 +0100
@@ -873,11 +873,11 @@
                          "change real name of user '%s' (%d) to '%s'",
                          user->user_name, user->uid, name);
 
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = "-c";
-                argv[2] = name;
-                argv[3] = "--";
-                argv[4] = user->user_name;
+                argv[0] = "/usr/sbin/pw";
+                argv[1] = "usermod";
+                argv[2] = user->user_name;
+                argv[3] = "-c";
+                argv[4] = name;
                 argv[5] = NULL;
 
                 error = NULL;
@@ -947,11 +947,11 @@
                          "change name of user '%s' (%d) to '%s'",
                          old_name, user->uid, name);
 
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = "-l";
-                argv[2] = name;
-                argv[3] = "--";
-                argv[4] = user->user_name;
+                argv[0] = "/usr/sbin/pw";
+                argv[1] = "usermod";
+                argv[2] = user->user_name;
+                argv[3] = "-n";
+                argv[4] = name;
                 argv[5] = NULL;
 
                 error = NULL;
@@ -1229,13 +1229,12 @@
                          "change home directory of user '%s' (%d) to '%s'",
                          user->user_name, user->uid, home_dir);
 
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = "-m";
-                argv[2] = "-d";
-                argv[3] = home_dir;
-                argv[4] = "--";
-                argv[5] = user->user_name;
-                argv[6] = NULL;
+                argv[0] = "/usr/sbin/pw";
+                argv[1] = "-d";
+                argv[2] = home_dir;
+                argv[3] = "-n";
+                argv[4] = user->user_name;
+                argv[5] = NULL;
 
                 error = NULL;
                 if (!spawn_with_login_uid (context, argv, &error)) {
@@ -1291,11 +1290,11 @@
                          "change shell of user '%s' (%d) to '%s'",
                          user->user_name, user->uid, shell);
 
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = "-s";
-                argv[2] = shell;
-                argv[3] = "--";
-                argv[4] = user->user_name;
+                argv[0] = "/usr/sbin/pw";
+                argv[1] = "usermod";
+                argv[2] = user->user_name;
+                argv[3] = "-s";
+                argv[4] = shell;
                 argv[5] = NULL;
 
                 error = NULL;
@@ -1551,11 +1550,10 @@
                 sys_log (context,
                          "%s account of user '%s' (%d)",
                          locked ? "locking" : "unlocking", user->user_name, user->uid);
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = locked ? "-L" : "-U";
-                argv[2] = "--";
-                argv[3] = user->user_name;
-                argv[4] = NULL;
+                argv[0] = "/usr/sbin/pw";
+                argv[1] = locked ? "lock" : "unlock";
+                argv[2] = user->user_name;
+                argv[3] = NULL;
 
                 error = NULL;
                 if (!spawn_with_login_uid (context, argv, &error)) {
@@ -1664,11 +1662,11 @@
 
                 g_free (groups);
 
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = "-G";
-                argv[2] = str->str;
-                argv[3] = "--";
-                argv[4] = user->user_name;
+                argv[0] = "/usr/sbin/pw";
+                argv[1] = "usermod";
+                argv[2] = user->user_name;
+                argv[3] = "-G";
+                argv[4] = str->str;
                 argv[5] = NULL;
 
                 g_string_free (str, FALSE);
@@ -1735,10 +1733,8 @@
                     mode == PASSWORD_MODE_NONE) {
 
                         argv[0] = "/usr/bin/passwd";
-                        argv[1] = "-d";
-                        argv[2] = "--";
-                        argv[3] = user->user_name;
-                        argv[4] = NULL;
+                        argv[1] = user->user_name;
+                        argv[2] = NULL;
 
                         error = NULL;
                         if (!spawn_with_login_uid (context, argv, &error)) {
@@ -1748,12 +1744,11 @@
                         }
 
                         if (mode == PASSWORD_MODE_SET_AT_LOGIN) {
-                                argv[0] = "/usr/bin/chage";
-                                argv[1] = "-d";
+                                argv[0] = "/usr/bin/chpass";
+                                argv[1] = "-e";
                                 argv[2] = "0";
-                                argv[3] = "--";
-                                argv[4] = user->user_name;
-                                argv[5] = NULL;
+                                argv[3] = user->user_name;
+                                argv[4] = NULL;
 
                                 error = NULL;
                                 if (!spawn_with_login_uid (context, argv, &error)) {
@@ -1777,11 +1772,10 @@
                         }
                 }
                 else if (user->locked) {
-                        argv[0] = "/usr/sbin/usermod";
-                        argv[1] = "-U";
-                        argv[2] = "--";
-                        argv[3] = user->user_name;
-                        argv[4] = NULL;
+                        argv[0] = "/usr/sbin/pw";
+                        argv[1] = "unlock";
+                        argv[2] = user->user_name;
+                        argv[3] = NULL;
 
                         error = NULL;
                         if (!spawn_with_login_uid (context, argv, &error)) {
@@ -1852,12 +1846,11 @@
 
         g_object_freeze_notify (G_OBJECT (user));
 
-        argv[0] = "/usr/sbin/usermod";
+        argv[0] = "/usr/bin/chpass";
         argv[1] = "-p";
         argv[2] = strings[0];
-        argv[3] = "--";
-        argv[4] = user->user_name;
-        argv[5] = NULL;
+        argv[3] = user->user_name;
+        argv[4] = NULL;
 
         error = NULL;
         if (!spawn_with_login_uid (context, argv, &error)) {
