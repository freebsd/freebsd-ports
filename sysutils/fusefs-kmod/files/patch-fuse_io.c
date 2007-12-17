--- fuse_module/fuse_io.c.orig	Tue Jun 19 09:35:22 2007
+++ fuse_module/fuse_io.c	Thu Dec 13 02:46:05 2007
@@ -148,7 +148,7 @@
 	}
 
 	if (uio->uio_resid == 0)
-		return (0);
+		goto out;
 
 	if (uio->uio_rw == UIO_WRITE && fp->f_flag & O_APPEND) {
 		if ((err = VOP_GETATTR(vp, &va, cred, td)))
