--- libnautilus-private/nautilus-desktop-icon-file.c.orig	Fri Jan 30 16:49:53 2004
+++ libnautilus-private/nautilus-desktop-icon-file.c	Fri Jan 30 16:50:52 2004
@@ -199,6 +199,10 @@
 	file_info->flags = GNOME_VFS_FILE_FLAGS_NONE;
 	file_info->link_count = 1;
 	file_info->size = 0;
+	/* Set a bogus owner and group on these files to prevent nowrite
+	 * emblems from showing up on the files. */
+	file_info->uid = -993;
+	file_info->gid = -993;
 	file_info->permissions =
 		GNOME_VFS_PERM_OTHER_WRITE |
 		GNOME_VFS_PERM_USER_READ |
