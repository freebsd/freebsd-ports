--- libgnomeui/gnome-app-helper.c.orig	Sun Mar 20 20:46:17 2005
+++ libgnomeui/gnome-app-helper.c	Sun Mar 20 20:49:57 2005
@@ -435,6 +435,8 @@
                 new_setting = gconf_value_get_bool(value);
         }
 
+	GDK_THREADS_ENTER();
+
         if (new_setting && (mi->image == NULL)) {
                 GtkWidget *pixmap;
                 GnomeUIPixmapType pixmap_type;
@@ -457,6 +459,8 @@
         } else if (!new_setting && (mi->image != NULL)) {
 		gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (mi), NULL);
         }
+
+	GDK_THREADS_LEAVE();
 }
 
 /* Note that this function is also used for toolbars, don't assume
@@ -1320,6 +1324,8 @@
 	if (entry->value->type != GCONF_VALUE_BOOL)
 		return;
 
+	GDK_THREADS_ENTER();
+
 	menu = GTK_WIDGET (user_data);
 	
 	if (gconf_value_get_bool (entry->value)) {
@@ -1329,6 +1335,7 @@
 
 		if (tearoff) {
 			/* Do nothing */
+			GDK_THREADS_LEAVE();
 			return;
 		}
 		
@@ -1345,6 +1352,7 @@
 
 		if (!tearoff) {
 			/* Do nothing */
+			GDK_THREADS_LEAVE();
 			return;
 		}
 		
@@ -1352,6 +1360,8 @@
 		gtk_widget_destroy (tearoff);
 		g_object_set_data (G_OBJECT (menu), "gnome-app-tearoff", NULL);
 	}
+
+	GDK_THREADS_LEAVE();
 }
 
 
@@ -2467,7 +2477,9 @@
                 }
         }
 
+	GDK_THREADS_ENTER();
         gtk_toolbar_set_style(toolbar, style);
+	GDK_THREADS_LEAVE();
 }
 
 static void
@@ -2511,7 +2523,9 @@
 			style = GTK_TOOLBAR_BOTH;
         }
 
+	GDK_THREADS_ENTER();
         gtk_toolbar_set_style(toolbar, style);
+	GDK_THREADS_LEAVE();
 }
 
 static void
