--- libgnomeui/gnome-icon-sel.c.orig	Sun Mar 20 20:40:05 2005
+++ libgnomeui/gnome-icon-sel.c	Sun Mar 20 20:42:24 2005
@@ -353,6 +353,8 @@
 		return FALSE;
 	}
 
+	GDK_THREADS_ENTER();
+
 	append_an_icon (gis, list->data);
 
 	g_free (list->data);
@@ -367,6 +369,8 @@
 				       (double)gis->_priv->load_i / gis->_priv->load_file_count);
 
 	gis->_priv->load_i ++;
+
+	GDK_THREADS_LEAVE();
 
 	return TRUE;
 }
