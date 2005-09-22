--- source/smbd/vfs.c.ORI	Wed Sep 29 19:37:44 2004
+++ source/smbd/vfs.c	Fri Apr 22 21:11:57 2005
@@ -717,6 +717,7 @@
 	pstring savedir;
 	pstring realdir;
 	size_t reallen;
+	int linklen;
 
 	if (!vfs_GetWd(conn, savedir)) {
 		DEBUG(0,("couldn't vfs_GetWd for %s %s\n", name, dir));
@@ -740,12 +741,16 @@
 		realdir[reallen] = 0;
 	}
 
-	if (conn->vfs_ops.readlink(conn, name, flink, sizeof(pstring) -1) != -1) {
+	if( (linklen = conn->vfs_ops.readlink(conn, name, flink, sizeof(pstring) -1)) != -1 ) {
+		flink[linklen] = '\0';
 		DEBUG(3,("reduce_name: file path name %s is a symlink\nChecking it's path\n", name));
 		if (*flink == '/') {
 			pstrcpy(cleanlink, flink);
 		} else {
-			pstrcpy(cleanlink, realdir);
+			char* cp;
+			pstrcpy( cleanlink, name );
+			if( (cp = strrchr( cleanlink, '/' )) != NULL )
+			  *cp = '\0';
 			pstrcat(cleanlink, "/");
 			pstrcat(cleanlink, flink);
 		}
