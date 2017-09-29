--- garcon-gtk/garcon-gtk-menu.c.orig	2017-04-16 04:26:38 UTC
+++ garcon-gtk/garcon-gtk-menu.c
@@ -650,8 +650,12 @@ garcon_gtk_menu_load_icon (const gchar *icon_name)
   gtk_icon_size_lookup (GTK_ICON_SIZE_MENU, &w, &h);
   size = MIN (w, h);
 
-  if (! gtk_icon_theme_has_icon (icon_theme, icon_name))
+  if (gtk_icon_theme_has_icon (icon_theme, icon_name))
     {
+	  pixbuf = gtk_icon_theme_load_icon (icon_theme, icon_name, size, 0, NULL);;
+    }
+  else
+    {
       if (g_path_is_absolute (icon_name))
         {
           pixbuf = gdk_pixbuf_new_from_file_at_scale (icon_name, w, h, TRUE, NULL);
@@ -684,22 +688,23 @@ garcon_gtk_menu_load_icon (const gchar *icon_name)
               g_free (name);
             }
         }
+    }
 
-      /* Turn the pixbuf into a gtk_image */
-      if (G_LIKELY (pixbuf))
-        {
-          /* scale the pixbuf down if it needs it */
-          GdkPixbuf *tmp = gdk_pixbuf_scale_simple (pixbuf, w, h, GDK_INTERP_BILINEAR);
-          g_object_unref (pixbuf);
-          pixbuf = tmp;
+  /* Turn the pixbuf into a gtk_image */
+  if (G_LIKELY (pixbuf))
+    {
+      /* scale the pixbuf down if it needs it */
+      GdkPixbuf *pixbuf_scaled = gdk_pixbuf_scale_simple (pixbuf, w, h, GDK_INTERP_BILINEAR);
+      g_object_unref (G_OBJECT (pixbuf));
 
-          image = gtk_image_new_from_pixbuf (pixbuf);
-          g_object_unref (G_OBJECT (pixbuf));
-        }
+      image = gtk_image_new_from_pixbuf (pixbuf_scaled);
+      g_object_unref (G_OBJECT (pixbuf_scaled));
     }
-
-  if (image == NULL)
-    image = gtk_image_new_from_icon_name (icon_name, GTK_ICON_SIZE_MENU);
+  else
+    {
+	  /* display the placeholder at least */
+	  image = gtk_image_new_from_icon_name (icon_name, GTK_ICON_SIZE_MENU);
+    }
 
   return image;
 }
