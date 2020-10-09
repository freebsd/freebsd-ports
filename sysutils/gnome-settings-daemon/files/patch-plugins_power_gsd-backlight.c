--- plugins/power/gsd-backlight.c.orig	2020-09-13 22:34:14 UTC
+++ plugins/power/gsd-backlight.c
@@ -61,9 +61,9 @@ enum {
         PROP_LAST,
 };
 
-#define SYSTEMD_DBUS_NAME                       "org.freedesktop.login1"
-#define SYSTEMD_DBUS_PATH                       "/org/freedesktop/login1/session/auto"
-#define SYSTEMD_DBUS_INTERFACE                  "org.freedesktop.login1.Session"
+#define SYSTEMD_DBUS_NAME                       "org.freedesktop.ConsoleKit"
+#define SYSTEMD_DBUS_PATH                       "/org/freedesktop/ConsoleKit/Manager"
+#define SYSTEMD_DBUS_INTERFACE                  "org.freedesktop.ConsoleKit.Manager"
 
 static GParamSpec *props[PROP_LAST];
 
