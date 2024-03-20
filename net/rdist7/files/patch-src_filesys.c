--- src/filesys.c.orig	1998-11-10 04:10:18 UTC
+++ src/filesys.c
@@ -430,8 +430,8 @@ int is_symlinked(path, statbuf, isvalid)
  */
 int getfilesysinfo(file, freespace, freefiles)
 	char *file;
-	long *freespace;
-	long *freefiles;
+	int64_t *freespace;
+	int64_t *freefiles;
 {
 #if	defined(STATFS_TYPE)
 	static statfs_t statfsbuf;
