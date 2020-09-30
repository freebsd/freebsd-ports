--- lib/ephy-flatpak-utils.c.orig	2020-09-11 23:16:40 UTC
+++ lib/ephy-flatpak-utils.c
@@ -28,7 +28,7 @@
 #include <fcntl.h>
 #include <gio/gio.h>
 #include <gio/gunixfdlist.h>
-#include <libportal/portal-gtk3.h>
+//#include <libportal/portal-gtk3.h>
 #include <string.h>
 #include <sys/stat.h>
 #include <sys/types.h>
@@ -63,44 +63,11 @@ ephy_is_running_inside_flatpak (void)
   return under_flatpak;
 }
 
-static void
-opened_uri (GObject      *object,
-            GAsyncResult *result,
-            gpointer      data)
-{
-  g_autoptr (XdpPortal) portal = XDP_PORTAL (object);
-  g_autoptr (GError) error = NULL;
-  gboolean open_dir = GPOINTER_TO_INT (data);
-  gboolean res;
 
-  if (open_dir)
-    res = xdp_portal_open_directory_finish (portal, result, &error);
-  else
-    res = xdp_portal_open_uri_finish (portal, result, &error);
-
-  if (!res)
-    g_warning ("%s", error->message);
-}
-
 static void
 ephy_open_uri (const char *uri,
                gboolean    is_dir)
 {
-  GApplication *application;
-  GtkWindow *window;
-  XdpParent *parent;
-  g_autoptr (XdpPortal) portal = xdp_portal_new ();
-
-  application = g_application_get_default ();
-  window = gtk_application_get_active_window (GTK_APPLICATION (application));
-  parent = xdp_parent_new_gtk (window);
-
-  if (is_dir)
-    xdp_portal_open_directory (g_steal_pointer (&portal), parent, uri, XDP_OPEN_URI_FLAG_ASK, NULL, opened_uri, GINT_TO_POINTER (TRUE));
-  else
-    xdp_portal_open_uri (g_steal_pointer (&portal), parent, uri, XDP_OPEN_URI_FLAG_ASK, NULL, opened_uri, GINT_TO_POINTER (FALSE));
-
-  xdp_parent_free (parent);
 }
 
 void
