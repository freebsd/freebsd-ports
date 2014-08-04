--- fs/fuse/fuse_io.c.orig
+++ fs/fuse/fuse_io.c
@@ -785,9 +785,9 @@ fuse_io_invalbuf(struct vnode *vp, struct thread *td)
 	fvdat->flag |= FN_FLUSHINPROG;
 
 	if (vp->v_bufobj.bo_object != NULL) {
-		VM_OBJECT_WLOCK(vp->v_bufobj.bo_object);
+		VM_OBJECT_LOCK(vp->v_bufobj.bo_object);
 		vm_object_page_clean(vp->v_bufobj.bo_object, 0, 0, OBJPC_SYNC);
-		VM_OBJECT_WUNLOCK(vp->v_bufobj.bo_object);
+		VM_OBJECT_UNLOCK(vp->v_bufobj.bo_object);
 	}
 	error = vinvalbuf(vp, V_SAVE, PCATCH, 0);
 	while (error) {
