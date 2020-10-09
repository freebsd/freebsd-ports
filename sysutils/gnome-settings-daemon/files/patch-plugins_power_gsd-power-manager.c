--- plugins/power/gsd-power-manager.c.orig	2020-09-13 22:34:14 UTC
+++ plugins/power/gsd-power-manager.c
@@ -70,9 +70,9 @@
 #define GSD_POWER_MANAGER_NOTIFY_TIMEOUT_SHORT          10 * 1000 /* ms */
 #define GSD_POWER_MANAGER_NOTIFY_TIMEOUT_LONG           30 * 1000 /* ms */
 
-#define SYSTEMD_DBUS_NAME                       "org.freedesktop.login1"
-#define SYSTEMD_DBUS_PATH                       "/org/freedesktop/login1"
-#define SYSTEMD_DBUS_INTERFACE                  "org.freedesktop.login1.Manager"
+#define SYSTEMD_DBUS_NAME                       "org.freedesktop.ConsoleKit"
+#define SYSTEMD_DBUS_PATH                       "/org/freedesktop/ConsoleKit/Manager"
+#define SYSTEMD_DBUS_INTERFACE                  "org.freedesktop.ConsoleKit.Manager"
 
 /* Time between notifying the user about a critical action and the action itself in UPower. */
 #define GSD_ACTION_DELAY 20
