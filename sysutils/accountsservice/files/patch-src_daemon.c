--- src/daemon.c.orig	2012-08-16 19:03:51.000000000 +0000
+++ src/daemon.c	2012-10-08 19:05:09.000000000 +0000
@@ -68,6 +68,7 @@
         "nobody4",
         "noaccess",
         "postgres",
+        "pgsql",
         "pvm",
         "rpm",
         "nfsnobody",
@@ -77,6 +78,7 @@
         "games",
         "man",
         "at",
+        "saned",
         NULL
 };
 
@@ -304,7 +306,11 @@
 
         /* Every iteration */
         fp = *state;
+#ifdef HAVE_FGETPWENT
         pwent = fgetpwent (fp);
+#else
+	pwent = getpwent ();
+#endif
         if (pwent != NULL) {
                 return pwent;
         }
@@ -1030,20 +1036,18 @@
 
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
-                argv[5] = "wheel";
-                argv[6] = "--";
-                argv[7] = cd->user_name;
+                argv[6] = "-G";
+                argv[7] = "wheel";
                 argv[8] = NULL;
         }
         else if (cd->account_type == ACCOUNT_TYPE_STANDARD) {
-                argv[4] = "--";
-                argv[5] = cd->user_name;
                 argv[6] = NULL;
         }
         else {
@@ -1250,16 +1254,15 @@
         g_remove (filename);
         g_free (filename);
 
-        argv[0] = "/usr/sbin/userdel";
+        argv[0] = "/usr/sbin/pw";
         if (ud->remove_files) {
-                argv[1] = "-f";
-                argv[2] = "-r";
-                argv[3] = "--";
-                argv[4] = pwent->pw_name;
-                argv[5] = NULL;
+                argv[1] = "userdel";
+                argv[2] = pwent->pw_name;
+                argv[3] = "-r";
+                argv[4] = NULL;
         }
         else {
-                argv[1] = "--";
+                argv[1] = "userdel";
                 argv[2] = pwent->pw_name;
                 argv[3] = NULL;
         }
