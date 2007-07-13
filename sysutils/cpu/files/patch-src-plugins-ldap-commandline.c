--- src/plugins/ldap/commandline.c.orig	2007-07-13 22:41:51.000000000 +0200
+++ src/plugins/ldap/commandline.c	2007-07-13 22:40:43.000000000 +0200
@@ -83,7 +83,7 @@
   if (passent == NULL)
     return -1;
   bzero (passent, sizeof (struct cpass));
-  (int) passent->sp_lstchg = passent->sp_min = passent->sp_max = -10;
+  passent->sp_lstchg = passent->sp_min = passent->sp_max = -10;
   passent->sp_warn = passent->sp_inact = passent->sp_expire = -10;
   passent->sp_flag = -10;
   passent->pw_gid = -10;
