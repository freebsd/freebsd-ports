--- vfs/direntry.c.orig	Thu Dec 26 08:21:43 2002
+++ vfs/direntry.c	Tue Jun 15 03:15:09 2004
@@ -217,13 +217,11 @@
 vfs_s_entry *
 vfs_s_find_entry_tree (vfs *me, vfs_s_inode *root, char *path, int follow, int flags)
 {
-    unsigned int pseg;
+    size_t pseg;
     vfs_s_entry *ent = NULL;
-    char p[MC_MAXPATHLEN] = "";
+    char p[MC_MAXPATHLEN] = "", *t = p;
 
     while (root){
-	int t;
-
 	while (*path == PATH_SEP)	/* Strip leading '/' */
 	    path++;
 
@@ -233,9 +231,14 @@
 	for (pseg = 0; path[pseg] && path[pseg] != PATH_SEP; pseg++)
 		;
 
-	strcat (p, PATH_SEP_STR);
-	strncpy (p + (t = strlen (p)), path, pseg);
-	p[t + pseg] = '\0';
+	if (t + pseg + sizeof (PATH_SEP_STR) > p + sizeof (p))
+	    ERRNOR (ENOMEM, NULL);
+
+	memcpy (t, PATH_SEP_STR, sizeof (PATH_SEP_STR) - 1);
+	t += sizeof (PATH_SEP_STR) - 1;
+	memcpy (t, path, pseg);
+	t += pseg;
+	*t = '\0';
 
 	for (ent = root->subdir; ent != NULL; ent = ent->next)
 	    if (strlen (ent->name) == pseg && (!strncmp (ent->name, path, pseg)))
@@ -375,21 +378,31 @@
 
     /* Convert absolute paths to relative ones */
     if (*linkname == PATH_SEP) {
-	char *p, *q;
+	char *p, *q, *r, *end;
 
 	for (p = path, q = entry->ino->linkname; *p == *q; p++, q++);
 	while (*(--q) != PATH_SEP);
 	q++;
+	r = buf;
+	end = buf + MC_MAXPATHLEN;
 	for (;; p++) {
 	    p = strchr (p, PATH_SEP);
 	    if (!p) {
-		strcat (buf, q);
+		size_t len = strlen (q);
+
+		if (r + len >= end)
+		  break;
+
+		memcpy (r, q, len + 1);
+		linkname = buf;
 		break;
 	    }
-	    strcat (buf, "..");
-	    strcat (buf, PATH_SEP_STR);
+
+	    if (r + sizeof (".." PATH_SEP_STR) > end)
+		break;
+	    memcpy (r, ".." PATH_SEP_STR, sizeof (".." PATH_SEP_STR) - 1);
+	    r += sizeof (".." PATH_SEP_STR) - 1;
 	}
-	linkname = buf;
     }
 
     return (MEDATA->find_entry) (me, entry->dir, linkname, follow - 1, 0);
@@ -622,8 +635,7 @@
 	return NULL;
 
     if (info->cur->name) {
-	strncpy(dir.dent.d_name, info->cur->name, MC_MAXPATHLEN);
-	dir.dent.d_name[MC_MAXPATHLEN] = 0;
+	g_strlcpy(dir.dent.d_name, info->cur->name, MC_MAXPATHLEN);
     } else {
 	vfs_die("Null in structure-cannot happen");
     }
@@ -729,8 +741,7 @@
     if (ino->linkname == NULL)
 	ERRNOR (EFAULT, -1);
 
-    strncpy (buf, ino->linkname, size);
-    *(buf+size-1) = 0;
+    g_strlcpy (buf, ino->linkname, size);
     return strlen (buf);
 }
 
@@ -1037,7 +1048,7 @@
     struct vfs_s_inode *ino;
     char buf[MC_MAXPATHLEN];
 
-    strncpy (buf, path, MC_MAXPATHLEN);
+    g_strlcpy (buf, path, MC_MAXPATHLEN);
     ino = vfs_s_inode_from_path (me, path, FL_FOLLOW | FL_NONE);
 
     if (!ino->localname)
