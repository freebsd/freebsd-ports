--- libgnomeui/gnome-entry.c.orig	Sun Mar 20 20:54:19 2005
+++ libgnomeui/gnome-entry.c	Sun Mar 20 20:54:20 2005
@@ -419,6 +419,8 @@
 {
 	GnomeEntry *gentry;
 
+	GDK_THREADS_ENTER();
+
 	gentry = GNOME_ENTRY (user_data);
 
 	/* If we're getting a notification from saving our own
@@ -427,10 +429,13 @@
 	if (gentry->_priv->saving_history) {
 		gentry->_priv->saving_history = FALSE;
 
+		GDK_THREADS_LEAVE();
 		return;
 	}
 
 	gnome_entry_load_history (gentry);
+
+	GDK_THREADS_LEAVE();
 }
 
 /* FIXME: Make this static */
