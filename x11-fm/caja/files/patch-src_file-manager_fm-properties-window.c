https://github.com/mate-desktop/caja/commit/13d04135dda5

--- src/file-manager/fm-properties-window.c.orig	2019-12-23 17:17:34 UTC
+++ src/file-manager/fm-properties-window.c
@@ -42,7 +42,6 @@
 #include <gtk/gtk.h>
 #include <gdk/gdkkeysyms.h>
 #include <glib/gi18n.h>
-#include <libmate-desktop/mate-desktop-thumbnail.h>
 #include <libcaja-extension/caja-property-page-provider.h>
 #include <libcaja-private/caja-entry.h>
 #include <libcaja-private/caja-extensions.h>
@@ -5622,10 +5621,11 @@ update_preview_callback (GtkFileChooser *icon_chooser,
 			scale = (double)gdk_pixbuf_get_height (pixbuf) /
 				gdk_pixbuf_get_width (pixbuf);
 
-			scaled_pixbuf = mate_desktop_thumbnail_scale_down_pixbuf
+			scaled_pixbuf = gdk_pixbuf_scale_simple
 				(pixbuf,
 				 PREVIEW_IMAGE_WIDTH,
-				 scale * PREVIEW_IMAGE_WIDTH);
+				 scale * PREVIEW_IMAGE_WIDTH,
+				 GDK_INTERP_HYPER);
 			g_object_unref (pixbuf);
 			pixbuf = scaled_pixbuf;
 		}
