--- src/fileops.c.orig	Fri Sep 20 11:27:42 2002
+++ src/fileops.c	Fri Nov 15 03:46:00 2002
@@ -144,6 +144,9 @@
 	result = gnome_vfs_get_file_info( dest, vfsinfo, options );
 	
 	if( result != GNOME_VFS_OK ) {
+	    	gnome_vfs_file_info_unref( vfsinfo );
+		vfsinfo = gnome_vfs_file_info_new();
+		gnome_vfs_get_file_info( source, vfsinfo, options );
 		if( ! mkdir_recursive( dest, vfsinfo->permissions ) ) {
 			gnome_vfs_file_info_unref( vfsinfo );
 			return FALSE;
@@ -159,7 +162,7 @@
 	gnome_vfs_file_info_unref( vfsinfo );
 
 	handle = NULL;
-	result = gnome_vfs_directory_open( &handle, dest, options );
+	result = gnome_vfs_directory_open( &handle, source, options );
 
 	if( result != GNOME_VFS_OK ) {
 		return FALSE;
@@ -298,6 +301,9 @@
 					result = GNOME_VFS_OK;
 				}
 				gnome_vfs_file_info_unref( info );
+			}
+			else if ( result == GNOME_VFS_ERROR_IS_DIRECTORY ) {
+			    result = GNOME_VFS_OK;
 			}
 			
 			ret = ( result == GNOME_VFS_OK );
