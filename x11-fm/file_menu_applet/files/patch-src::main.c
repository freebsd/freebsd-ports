--- src/main.c.orig	Thu May 30 22:31:15 2002
+++ src/main.c	Fri Jun 14 23:13:34 2002
@@ -318,13 +318,12 @@
 	g_timer_start (dm->timer);
 	g_timer_elapsed (dm->timer, &dm->last_time);
 
-	if (fma->icon_menus) {
+	if (!fma->icon_menus) {
 		options = GNOME_VFS_FILE_INFO_FOLLOW_LINKS
-			| GNOME_VFS_FILE_INFO_FORCE_FAST_MIME_TYPE
 			| GNOME_VFS_FILE_INFO_GET_MIME_TYPE;
 	} else {
 		options = GNOME_VFS_FILE_INFO_FOLLOW_LINKS
-			| GNOME_VFS_FILE_INFO_GET_MIME_TYPE;
+			| GNOME_VFS_FILE_INFO_FORCE_FAST_MIME_TYPE;
 	}
 
 	result = gnome_vfs_directory_visit 
@@ -559,6 +558,10 @@
 
 	if (!fma->menu_label)
 		fma->menu_label = strdup ("Home Directory");
+	if (!fma->dir_watch)
+		fma->dir_watch  = strdup ("~/");
+	if (fma->icon_menus == "(null)")
+		fma->icon_menus = strdup ("true");
 
 	/* Create */
 	fma->menu_bar = gtk_menu_bar_new ();
