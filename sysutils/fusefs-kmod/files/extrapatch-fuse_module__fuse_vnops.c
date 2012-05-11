--- fuse_module/fuse_vnops.c.orig	2012-05-11 14:59:59.000000000 +0800
+++ fuse_module/fuse_vnops.c	2012-05-11 15:00:05.000000000 +0800
@@ -663,7 +663,7 @@
 	if ((err = fuse_recyc_backend(vp, td)))
 		return err;
 
-	vrecycle(vp, td);
+	vrecycle(vp);
 
 	return (0);
 }
