--- src/gnome-mount.c.orig	2010-12-26 14:53:42.000000000 +0100
+++ src/gnome-mount.c	2010-12-26 18:19:30.000000000 +0100
@@ -38,7 +38,7 @@
 
 #include <glib/gi18n.h>
 #include <gconf/gconf-client.h>
-#include <gdk/gdkx.h>
+#include <gtk/gtk.h>
 #include "copy-paste/gnome-password-dialog.h"
 #include <gnome-keyring.h>
 #include <libnotify/notify.h>
@@ -1577,8 +1577,7 @@
 		message = g_strdup_printf (_("There is data that needs to be written to the device %s before it can be removed. Please do not remove the media or disconnect the drive."), unmount_note_drive_name);
 		unmount_note = notify_notification_new (summary,
 							message,
-							"gnome-dev-harddisk", /* TODO: use appropriate icon */
-							NULL);
+							"gnome-dev-harddisk");
 		if (unmount_note == NULL) {
 			g_warning ("Cannot create note for unmount cache sync");
 		} else {
