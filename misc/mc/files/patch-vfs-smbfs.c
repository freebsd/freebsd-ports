--- vfs/smbfs.c.orig	Sat Jan 25 03:37:29 2003
+++ vfs/smbfs.c	Tue Jun 15 03:15:09 2004
@@ -785,8 +785,7 @@
 #endif
 	return NULL;
     }
-    strncpy(dirent_dest, smbfs_info->current->text, MC_MAXPATHLEN);
-    dirent_dest[MC_MAXPATHLEN] = 0;
+    g_strlcpy(dirent_dest, smbfs_info->current->text, MC_MAXPATHLEN);
     smbfs_info->current = smbfs_info->current->next;
 
     compute_namelen(&smbfs_readdir_data.dent);
