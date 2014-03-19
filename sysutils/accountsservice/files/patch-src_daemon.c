--- src/daemon.c.orig	2013-10-15 22:25:19.000000000 +0200
+++ src/daemon.c	2014-03-15 15:33:49.000000000 +0100
@@ -50,9 +50,8 @@
 #define PATH_PASSWD "/etc/passwd"
 #define PATH_SHADOW "/etc/shadow"
 #define PATH_GROUP "/etc/group"
-#define PATH_GDM_CUSTOM "/etc/gdm/custom.conf"
+#define PATH_GDM_CUSTOM "/usr/local/etc/gdm/custom.conf"
 #ifdef HAVE_UTMPX_H
-#define PATH_WTMP _PATH_WTMPX
 #endif
 
 enum {
@@ -73,7 +72,7 @@
         GFileMonitor *group_monitor;
         GFileMonitor *gdm_monitor;
 #ifdef HAVE_UTMPX_H
-        GFileMonitor *wtmp_monitor;
+//        GFileMonitor *wtmp_monitor;
 #endif
 
         guint reload_id;
@@ -162,6 +161,10 @@
         g_free (previous_login);
 }
 
+#ifndef HAVE_FGETPWENT
+#include "fgetpwent.c"
+#endif
+
 static struct passwd *
 entry_generator_wtmp (GHashTable *users,
                       gpointer   *state)
@@ -183,7 +186,7 @@
                         return NULL;
                 }
 #else
-                utmpxname (PATH_WTMP);
+//                utmpxname (PATH_WTMP);
                 setutxent ();
 #endif
                 *state = g_new (WTmpGeneratorState, 1);
@@ -697,11 +700,6 @@
                                                      PATH_GROUP,
                                                      on_users_monitor_changed);
 
-#ifdef HAVE_UTMPX_H
-        daemon->priv->wtmp_monitor = setup_monitor (daemon,
-                                                    PATH_WTMP,
-                                                    on_users_monitor_changed);
-#endif
 
         daemon->priv->gdm_monitor = setup_monitor (daemon,
                                                    PATH_GDM_CUSTOM,
@@ -1061,20 +1059,18 @@
 
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
