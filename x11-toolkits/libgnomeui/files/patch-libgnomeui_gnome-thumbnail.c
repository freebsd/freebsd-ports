--- libgnomeui/gnome-thumbnail.c.orig	Sat Jan 21 23:11:21 2006
+++ libgnomeui/gnome-thumbnail.c	Sat Jan 21 23:10:52 2006
@@ -994,11 +994,7 @@ gnome_thumbnail_factory_generate_thumbna
     return NULL;
 
   width = gdk_pixbuf_get_width (pixbuf);
-  g_object_set_data_full (G_OBJECT (pixbuf), "gnome-thumbnail-width",
-			  g_strdup_printf ("%d", width), g_free);
   height = gdk_pixbuf_get_height (pixbuf);
-  g_object_set_data_full (G_OBJECT (pixbuf), "gnome-thumbnail-height",
-			  g_strdup_printf ("%d", height), g_free);
 
   if (width > size || height > size)
     {
@@ -1011,6 +1007,13 @@ gnome_thumbnail_factory_generate_thumbna
       g_object_unref (pixbuf);
       pixbuf = scaled;
     }
+
+  width = gdk_pixbuf_get_width (pixbuf);
+  g_object_set_data_full (G_OBJECT (pixbuf), "gnome-thumbnail-width",
+			  g_strdup_printf ("%d", width), g_free);
+  height = gdk_pixbuf_get_height (pixbuf);
+  g_object_set_data_full (G_OBJECT (pixbuf), "gnome-thumbnail-height",
+			  g_strdup_printf ("%d", height), g_free);
   
   return pixbuf;
 }
