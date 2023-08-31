FreeBSD ConsoleKit is patched to return proper IDs instead D-Bus paths, so
adapt Polkit to this case.

--- src/polkitbackend/polkitbackendsessionmonitor.c.orig	2023-07-28 12:34:38 UTC
+++ src/polkitbackend/polkitbackendsessionmonitor.c
@@ -385,7 +385,7 @@ polkit_backend_session_monitor_get_session_for_subject
 
   if (POLKIT_IS_UNIX_PROCESS (subject))
     {
-      const gchar *session_id;
+      const gchar *session_path, *session_id;
       GVariant *result;
       result = g_dbus_connection_call_sync (monitor->system_bus,
                                             "org.freedesktop.ConsoleKit",
@@ -400,14 +400,16 @@ polkit_backend_session_monitor_get_session_for_subject
                                             error);
       if (result == NULL)
         goto out;
-      g_variant_get (result, "(&o)", &session_id);
+      g_variant_get (result, "(&o)", &session_path);
+      session_id = g_path_get_basename (session_path);
       session = polkit_unix_session_new (session_id);
+      g_free (session_id);
       g_variant_unref (result);
     }
   else if (POLKIT_IS_SYSTEM_BUS_NAME (subject))
     {
       guint32 pid;
-      const gchar *session_id;
+      const gchar *session_path, *session_id;
       GVariant *result;
 
       result = g_dbus_connection_call_sync (monitor->system_bus,
@@ -439,8 +441,10 @@ polkit_backend_session_monitor_get_session_for_subject
                                             error);
       if (result == NULL)
         goto out;
-      g_variant_get (result, "(&o)", &session_id);
+      g_variant_get (result, "(&o)", &session_path);
+      session_id = g_path_get_basename (session_path);
       session = polkit_unix_session_new (session_id);
+      g_free (session_id);
       g_variant_unref (result);
     }
   else
