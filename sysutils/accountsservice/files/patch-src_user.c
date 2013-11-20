--- src/user.c.orig	2012-08-16 19:03:51.000000000 +0000
+++ src/user.c	2012-10-08 19:13:02.000000000 +0000
@@ -546,11 +546,11 @@
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
@@ -620,11 +620,11 @@
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
@@ -964,11 +964,11 @@
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
@@ -1224,11 +1224,10 @@
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
@@ -1315,11 +1314,11 @@
 
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
@@ -1386,10 +1385,8 @@
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
@@ -1399,12 +1396,11 @@
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
@@ -1428,11 +1424,10 @@
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
@@ -1503,12 +1498,11 @@
 
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
