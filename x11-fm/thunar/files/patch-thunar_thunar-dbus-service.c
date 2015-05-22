--- thunar/thunar-dbus-service.c.orig	2015-05-14 17:33:17 UTC
+++ thunar/thunar-dbus-service.c
@@ -357,6 +357,7 @@ thunar_dbus_service_connect_trash_bin (T
           g_signal_connect_swapped (G_OBJECT (dbus_service->trash_bin), "changed",
                                     G_CALLBACK (thunar_dbus_service_trash_bin_changed),
                                     dbus_service);
+          thunar_file_reload_idle (dbus_service->trash_bin);
         }
       g_object_unref (trash_bin_path);
     }
