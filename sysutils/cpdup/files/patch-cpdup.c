
$FreeBSD$

--- cpdup.c.orig
+++ cpdup.c
@@ -321,6 +321,11 @@
 
     if (lstat(spath, &st1) != 0)
 	return(0);
+#ifdef SF_SNAPSHOT
+    /* skip snapshot files: we cannot handle files larger than file system */
+    if (st1.st_flags & SF_SNAPSHOT)
+	 return(0);
+#endif
     st2.st_mode = 0;	/* in case lstat fails */
     st2.st_flags = 0;	/* in case lstat fails */
     if (dpath && lstat(dpath, &st2) == 0)
