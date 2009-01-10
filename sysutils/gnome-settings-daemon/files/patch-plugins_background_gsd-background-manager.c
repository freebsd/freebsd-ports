--- plugins/background/gsd-background-manager.c.orig	2008-11-03 13:25:29.000000000 -0600
+++ plugins/background/gsd-background-manager.c	2008-11-03 13:28:16.000000000 -0600
@@ -160,6 +160,18 @@
         GdkDisplay *display;
         int         n_screens;
         int         i;
+        GConfClient *client;
+        gboolean    enabled;
+
+        client = gconf_client_get_default ();
+
+        enabled = gconf_client_get_bool (client,
+                "/desktop/gnome/background/draw_background",
+                NULL);
+        g_object_unref (client);
+
+        if (!enabled)
+                return FALSE;
 
         if (nautilus_is_running ()) {
                 return;
