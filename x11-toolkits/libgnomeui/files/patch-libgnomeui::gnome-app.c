--- libgnomeui/gnome-app.c.orig	Sun Mar 20 20:51:20 2005
+++ libgnomeui/gnome-app.c	Sun Mar 20 20:52:01 2005
@@ -269,7 +269,9 @@
 		detachable = gconf_value_get_bool (entry->value);
 		
 		/* Update */
+		GDK_THREADS_ENTER();
 		bonobo_dock_item_set_locked (item, !detachable);
+		GDK_THREADS_LEAVE();
 	}
 }
 
