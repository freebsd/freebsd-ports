--- libgnomeui/gnome-pixmap-entry.c.orig	Sun Mar 20 20:34:49 2005
+++ libgnomeui/gnome-pixmap-entry.c	Sun Mar 20 20:38:30 2005
@@ -237,6 +237,8 @@
 {
 	GSList *li,*tmp;
 
+	GDK_THREADS_ENTER();
+
 	tmp = changed_pentries;
 	changed_pentries = NULL;
 	if(tmp) {
@@ -244,9 +246,13 @@
 			refresh_preview(li->data);
 		}
 		g_slist_free(tmp);
+
+		GDK_THREADS_LEAVE();
 		return TRUE;
 	}
 	change_timeout = 0;
+
+	GDK_THREADS_LEAVE();
 
 	return FALSE;
 }
