--- fuse_module/fuse_io.c.orig	2007-06-19 16:35:22.000000000 +0400
+++ fuse_module/fuse_io.c	2008-01-20 20:47:05.000000000 +0300
@@ -139,7 +139,11 @@
 	struct vnode *vp = fp->f_vnode;
 	int err = 0;
 
+#if __FreeBSD_version > 800009
+	vn_lock(vp, LK_EXCLUSIVE | LK_RETRY);
+#else
 	vn_lock(vp, LK_EXCLUSIVE | LK_RETRY, td);
+#endif
 
 	ASSERT_VOP_LOCKED__FH(vp);
 	if (_file_is_bad(fp) || ! _file_is_fat(fp)) {
@@ -148,7 +152,7 @@
 	}
 
 	if (uio->uio_resid == 0)
-		return (0);
+		goto out;
 
 	if (uio->uio_rw == UIO_WRITE && fp->f_flag & O_APPEND) {
 		if ((err = VOP_GETATTR(vp, &va, cred, td)))
@@ -166,7 +170,11 @@
 	fp->f_nextoff = uio->uio_offset;
 
 out:
+#if __FreeBSD_version > 800009
+	VOP_UNLOCK(vp, 0);
+#else
 	VOP_UNLOCK(vp, 0, td);
+#endif
 
 	DEBUG("leaving with %d\n", err);
 	return (err);
