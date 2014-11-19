--- src/daemon.c.orig	2014-03-23 09:36:37.194365289 +0000
+++ src/daemon.c	2014-03-23 09:36:39.836364714 +0000
@@ -48,7 +48,7 @@
 #define PATH_PASSWD "/etc/passwd"
 #define PATH_SHADOW "/etc/shadow"
 #define PATH_GROUP "/etc/group"
-#define PATH_GDM_CUSTOM "/etc/gdm/custom.conf"
+#define PATH_GDM_CUSTOM "/usr/local/etc/gdm/custom.conf"
 
 enum {
         PROP_0,
@@ -892,20 +892,18 @@
 
         sys_log (context, "create user '%s'", cd->user_name);
 
-        argv[0] = "/usr/sbin/useradd";
-        argv[1] = "-m";
-        argv[2] = "-c";
-        argv[3] = cd->real_name;
+        argv[0] = "/usr/sbin/pw";
+        argv[1] = "useradd";
+        argv[2] = cd->user_name;
+        argv[3] = "-m";
+        argv[4] = "-c";
+        argv[5] = cd->real_name;
         if (cd->account_type == ACCOUNT_TYPE_ADMINISTRATOR) {
-                argv[4] = "-G";
-                argv[5] = ADMIN_GROUP;
-                argv[6] = "--";
-                argv[7] = cd->user_name;
+                argv[6] = "-G";
+                argv[7] = ADMIN_GROUP;
                 argv[8] = NULL;
         }
         else if (cd->account_type == ACCOUNT_TYPE_STANDARD) {
-                argv[4] = "--";
-                argv[5] = cd->user_name;
                 argv[6] = NULL;
         }
         else {
