login1 -> ConsoleKit

Index: panels/power/cc-power-panel.c
--- panels/power/cc-power-panel.c.orig
+++ panels/power/cc-power-panel.c
@@ -903,9 +903,9 @@ can_suspend_or_hibernate (CcPowerPanel *self,
     }
 
   variant = g_dbus_connection_call_sync (connection,
-                                         "org.freedesktop.login1",
-                                         "/org/freedesktop/login1",
-                                         "org.freedesktop.login1.Manager",
+                                         "org.freedesktop.ConsoleKit",
+                                         "/org/freedesktop/ConsoleKit/Manager",
+                                         "org.freedesktop.ConsoleKit.Manager",
                                          method_name,
                                          NULL,
                                          NULL,
