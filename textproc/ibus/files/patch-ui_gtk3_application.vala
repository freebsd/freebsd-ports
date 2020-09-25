--- ui/gtk3/application.vala.orig	2020-02-21 12:43:01 UTC
+++ ui/gtk3/application.vala
@@ -69,7 +69,7 @@ class Application {
     }
 
     private void bus_name_acquired_cb(DBusConnection connection,
-                                      string sender_name,
+                                      string? sender_name,
                                       string object_path,
                                       string interface_name,
                                       string signal_name,
@@ -80,7 +80,7 @@ class Application {
     }
 
     private void bus_name_lost_cb(DBusConnection connection,
-                                  string sender_name,
+                                  string? sender_name,
                                   string object_path,
                                   string interface_name,
                                   string signal_name,
