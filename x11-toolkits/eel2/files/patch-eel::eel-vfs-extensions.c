
$FreeBSD$

--- eel/eel-vfs-extensions.c	2001/12/20 13:41:21	1.1
+++ eel/eel-vfs-extensions.c	2001/12/20 13:47:36
@@ -116,7 +116,8 @@
 
 	/* Return the file. */
 	*file_size = total_bytes_read;
-	*file_contents = g_realloc (buffer, total_bytes_read);
+	*file_contents = g_realloc (buffer, total_bytes_read + 1);
+	(*file_contents)[total_bytes_read] = '\0';
 	return GNOME_VFS_OK;
 }
 
