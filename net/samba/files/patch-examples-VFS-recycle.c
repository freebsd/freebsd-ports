--- examples/VFS/recycle.c.orig	Wed May  8 21:30:11 2002
+++ examples/VFS/recycle.c	Thu May  9 02:19:32 2002
@@ -238,15 +238,18 @@
 		return default_vfs_ops.unlink(conn,fname);
 	}
 
-	base = strrchr(fname, '/') + 1;
-	if(base == (char*)1)
-		ext = strrchr(fname, '.');
-	else
-		ext = strrchr(base, '.');
-
+	base = strrchr(fname, '/');
 	pstrcpy(bin, recycle_bin);
 	pstrcat(bin, "/");
-	pstrcat(bin, base);
+
+	if(base == NULL) {
+		ext = strrchr(fname, '.');
+		pstrcat(bin, fname);
+	} else {
+		ext = strrchr(base, '.');
+		pstrcat(bin, base+1);
+	}
+	DEBUG(3, ("recycle bin: base %s, ext %s, fname %s, bin %s\n", base, ext, fname, bin));
 
 	if(strcmp(fname,bin) == 0) {
 		DEBUG(3, ("recycle bin: file %s exists, purging...\n", fname));
@@ -254,6 +257,8 @@
 	}
 
 	len = strlen(bin);
+	if ( ext != NULL)
+		len = len - strlen(ext);
 	addlen = sizeof(pstring)-len-1;
 	while(recycle_file_exist(conn,bin)) {
 		slprintf(bin+len, addlen, " (Copy #%d)", i++);
