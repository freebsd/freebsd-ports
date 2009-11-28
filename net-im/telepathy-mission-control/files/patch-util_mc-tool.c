--- util/mc-tool.c.orig	2009-09-22 22:49:32.000000000 -0400
+++ util/mc-tool.c	2009-09-22 22:50:39.000000000 -0400
@@ -1103,7 +1103,7 @@ main (int argc, char **argv)
     McAccountManager *am = NULL;
     McAccount *a = NULL;
     DBusGConnection *dbus_conn;
-    TpDBusDaemon *daemon;
+    TpDBusDaemon *td_daemon;
 
     g_type_init ();
 
@@ -1114,19 +1114,19 @@ main (int argc, char **argv)
     command.common.ret = 1;
 
     dbus_conn = tp_get_bus ();
-    daemon = tp_dbus_daemon_new (dbus_conn);
+    td_daemon = tp_dbus_daemon_new (dbus_conn);
     dbus_g_connection_unref (dbus_conn);
 
     if (command.common.account == NULL) {
-	am = mc_account_manager_new (daemon);
+	am = mc_account_manager_new (td_daemon);
 	mc_account_manager_call_when_ready (am, manager_ready, NULL);
     }
     else {
 	command.common.account = prefix (command.common.account);
-	a = mc_account_new (daemon, command.common.account);
+	a = mc_account_new (td_daemon, command.common.account);
 	mc_account_call_when_ready (a, account_ready, NULL);
     }
-    g_object_unref (daemon);
+    g_object_unref (td_daemon);
 
     main_loop = g_main_loop_new (NULL, FALSE);
     g_main_loop_run (main_loop);
