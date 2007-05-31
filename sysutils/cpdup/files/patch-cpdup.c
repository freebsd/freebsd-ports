
$FreeBSD$

--- cpdup.c.orig	Thu Sep 21 06:09:28 2006
+++ cpdup.c	Wed May 30 17:27:55 2007
@@ -463,6 +463,11 @@
 
     if (hc_lstat(&SrcHost, spath, &st1) != 0)
 	return(0);
+#ifdef SF_SNAPSHOT
+    /* skip snapshot files because they're sparse and _huge_ */
+    if (st1.st_flags & SF_SNAPSHOT)
+	return(0);
+#endif
     st2.st_mode = 0;	/* in case lstat fails */
     st2.st_flags = 0;	/* in case lstat fails */
     if (dpath && hc_lstat(&DstHost, dpath, &st2) == 0)
