--- src/gnome-mount.c.orig	Mon Sep  4 21:41:09 2006
+++ src/gnome-mount.c	Mon Sep  4 21:45:53 2006
@@ -42,7 +42,7 @@
 #include <libhal.h>
 #include <libhal-storage.h>
 
-#include <mntent.h>
+#include "mntent.h"
 
 static DBusConnection *dbus_connection;
 static LibHalContext *hal_ctx;
@@ -477,7 +477,7 @@
 
 		mount_point = NULL;
 		device_file = get_dev_file (volume, drive);
-
+#ifdef __linux__
 		if (device_file != NULL) {
 			FILE *f;
 			struct mntent mnt;
@@ -497,7 +497,7 @@
 				endmntent (f);
 			}
 		}
-
+#endif
 		g_print (_("Mounted %s at \"%s\"\n"), device_file, mount_point);
 		g_free (mount_point);
 	}
