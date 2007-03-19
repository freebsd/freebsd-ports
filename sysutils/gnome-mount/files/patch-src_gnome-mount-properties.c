--- src/gnome-mount-properties.c.orig	Sun Dec  3 02:38:14 2006
+++ src/gnome-mount-properties.c	Sun Dec  3 02:39:27 2006
@@ -27,6 +27,8 @@
 #include <libhal.h>
 #include <libhal-storage.h>
 
+#include <gtk/gtk.h>
+
 #include <libnautilus-extension/nautilus-extension-types.h>
 #include <libnautilus-extension/nautilus-info-provider.h>
 #include <libnautilus-extension/nautilus-property-page-provider.h>
@@ -202,7 +204,8 @@ gnome_mount_properties_plugin_register_t
 		NULL,
 		sizeof (GObject),
 		0,
-		(GInstanceInitFunc) NULL
+		(GInstanceInitFunc) NULL,
+		(const GTypeValueTable *) NULL
 	};
 
 	static const GInterfaceInfo property_page_provider_iface_info = {
