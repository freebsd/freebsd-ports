--- vfs/extfs.c.orig	Thu Dec 26 03:42:59 2002
+++ vfs/extfs.c	Tue Jun 15 03:15:09 2004
@@ -888,8 +888,7 @@
     if (!*info)
 	return NULL;
 
-    strncpy(dir.dent.d_name, (*info)->name, MC_MAXPATHLEN);
-    dir.dent.d_name[MC_MAXPATHLEN] = 0;
+    g_strlcpy(dir.dent.d_name, (*info)->name, MC_MAXPATHLEN);
 
     compute_namelen(&dir.dent);
     *info = (*info)->next_in_dir;
@@ -1002,10 +1001,10 @@
     if (entry == NULL)
     	return -1;
     if (!S_ISLNK (entry->inode->mode)) ERRNOR (EINVAL, -1);
-    if (size > (i = strlen (entry->inode->linkname))) {
-    	size = i;
+    if (size < (i = strlen (entry->inode->linkname))) {
+    	i = size;
     }
-    strncpy (buf, entry->inode->linkname, i);
+    memcpy (buf, entry->inode->linkname, i);
     return i;
 }
 
