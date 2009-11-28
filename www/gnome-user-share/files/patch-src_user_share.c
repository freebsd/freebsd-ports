--- src/user_share.c.orig	2009-09-26 09:10:16.000000000 -0400
+++ src/user_share.c	2009-09-26 09:13:52.000000000 -0400
@@ -26,7 +26,9 @@
 #include <gdk/gdkx.h>
 #include <gtk/gtk.h>
 #include <glib/gi18n.h>
+#ifndef __FreeBSD__
 #include <bluetooth-client.h>
+#endif
 #include <X11/Xlib.h>
 
 #include "user_share.h"
@@ -58,7 +60,9 @@
 static guint disabled_timeout_tag = 0;
 static gboolean has_console = TRUE;
 
+#ifndef __FreeBSD__
 static BluetoothClient *client = NULL;
+#endif
 static gboolean bluetoothd_enabled = FALSE;
 
 #define OBEX_ENABLED (bluetoothd_enabled && has_console)
@@ -224,6 +228,7 @@ consolekit_init (void)
 	dbus_g_connection_unref (dbus_connection);
 }
 
+#ifndef __FreeBSD__
 static void
 default_adapter_changed (GObject    *gobject,
 			 GParamSpec *pspec,
@@ -261,6 +266,7 @@ bluez_init (void)
 	g_signal_connect (G_OBJECT (client), "notify::default-adapter-powered",
 			  G_CALLBACK (default_adapter_changed), NULL);
 }
+#endif
 
 char *
 lookup_public_dir (void)
@@ -590,7 +596,9 @@ main (int argc, char **argv)
 
 	g_object_unref (client);
 
+#ifndef __FreeBSD__
 	bluez_init ();
+#endif
 	consolekit_init ();
 
 	/* Initial setting */
