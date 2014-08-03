--- fs/fuse/fuse_node.c.orig
+++ fs/fuse/fuse_node.c
@@ -362,7 +362,7 @@ fuse_vnode_setsize(struct vnode *vp, struct ucred *cred, off_t newsize)
 	fvdat->flag |= FN_SIZECHANGE;
 
 	if (newsize < oldsize) {
-		err = vtruncbuf(vp, cred, newsize, fuse_iosize(vp));
+		err = vtruncbuf(vp, cred, curthread, newsize, fuse_iosize(vp));
 	}
 	vnode_pager_setsize(vp, newsize);
 	return err;
