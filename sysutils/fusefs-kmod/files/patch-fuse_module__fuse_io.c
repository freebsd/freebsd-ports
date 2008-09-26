--- fuse_module/fuse_io.c.orig	2008-02-05 00:25:57.000000000 -0500
+++ fuse_module/fuse_io.c	2008-09-26 13:15:56.000000000 -0400
@@ -157,7 +157,11 @@
 		goto out;
 
 	if (uio->uio_rw == UIO_WRITE && fp->f_flag & O_APPEND) {
-		if ((err = VOP_GETATTR(vp, &va, cred, td)))
+		if ((err = VOP_GETATTR(vp, &va, cred
+#if VOP_GETATTR_TAKES_THREAD
+		    , td
+#endif
+		    )))
 			goto out;
 		uio->uio_offset = va.va_size;
 	} else if ((flags & FOF_OFFSET) == 0)
@@ -823,7 +827,11 @@
 #if FUSELIB_CONFORM_BIOREAD
 		struct vattr va;
 
-		if ((err = VOP_GETATTR(vp, &va, cred, curthread)))
+		if ((err = VOP_GETATTR(vp, &va, cred
+#if VOP_GETATTR_TAKES_THREAD
+		    , curthread
+#endif
+		    )))
 			goto out;
 #endif
 
