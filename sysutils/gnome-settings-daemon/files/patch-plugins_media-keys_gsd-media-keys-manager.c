Inhibit support (login1 -> ConsoleKit).

Index: plugins/media-keys/gsd-media-keys-manager.c
--- plugins/media-keys/gsd-media-keys-manager.c.orig
+++ plugins/media-keys/gsd-media-keys-manager.c
@@ -123,9 +123,9 @@ static const gchar introspection_xml[] =
 #define VOLUME_STEP_PRECISE 2
 #define MAX_VOLUME 65536.0
 
-#define SYSTEMD_DBUS_NAME                       "org.freedesktop.login1"
-#define SYSTEMD_DBUS_PATH                       "/org/freedesktop/login1"
-#define SYSTEMD_DBUS_INTERFACE                  "org.freedesktop.login1.Manager"
+#define SYSTEMD_DBUS_NAME                       "org.freedesktop.ConsoleKit"
+#define SYSTEMD_DBUS_PATH                       "/org/freedesktop/ConsoleKit/Manager"
+#define SYSTEMD_DBUS_INTERFACE                  "org.freedesktop.ConsoleKit.Manager"
 
 #define AUDIO_SELECTION_DBUS_NAME               "org.gnome.Shell.AudioDeviceSelection"
 #define AUDIO_SELECTION_DBUS_PATH               "/org/gnome/Shell/AudioDeviceSelection"
