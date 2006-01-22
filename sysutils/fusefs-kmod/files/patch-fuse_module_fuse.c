--- fuse_module/fuse.c.orig	Fri Jan 20 15:14:36 2006
+++ fuse_module/fuse.c	Fri Jan 20 15:18:08 2006
@@ -2604,7 +2604,7 @@
 	        fufh->useco);
 	if (! fufh->fp && fufh->useco == 0) {
 		LIST_REMOVE(fufh, fh_link);
-		fuse_send_release(vp, td, cred, fufh, fufh->mode, (int)param);
+		fuse_send_release(vp, td, cred, fufh, fufh->mode, (long)param);
 	}
 
 	return (0);		
