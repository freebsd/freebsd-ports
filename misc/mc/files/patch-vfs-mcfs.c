--- vfs/mcfs.c.orig	Fri Nov 15 13:49:39 2002
+++ vfs/mcfs.c	Tue Jun 15 03:15:09 2004
@@ -756,8 +756,7 @@
 	return NULL;
     }
     dirent_dest = mcfs_readdir_data.dent.d_name;
-    strncpy (dirent_dest, mcfs_info->current->text, MC_MAXPATHLEN);
-    dirent_dest[MC_MAXPATHLEN] = 0;
+    g_strlcpy (dirent_dest, mcfs_info->current->text, MC_MAXPATHLEN);
     cached_lstat_info = &mcfs_info->current->my_stat;
     mcfs_info->current = mcfs_info->current->next;
 
@@ -985,9 +984,12 @@
     if (!rpc_get (mc->sock, RPC_STRING, &stat_str, RPC_END))
 	return the_error (-1, EIO);
 
-    strncpy (buf, stat_str, size);
+    status = strlen (stat_str);
+    if (status < size)
+	size = status;
+    memcpy (buf, stat_str, size);
     g_free (stat_str);
-    return strlen (buf);
+    return size;
 }
 
 static int
