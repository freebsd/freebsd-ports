--- fuse_module/fuse_vnops.c.orig	2008-02-05 13:25:57.000000000 +0800
+++ fuse_module/fuse_vnops.c	2008-10-19 13:31:53.000000000 +0800
@@ -799,8 +799,11 @@
 	struct vnode *vp = ap->a_vp;
 	struct vattr *vap = ap->a_vap;
 	struct ucred *cred = ap->a_cred;
+#if VOP_GETATTR_TAKES_THREAD
 	struct thread *td = ap->a_td;
-
+#else
+	struct thread *td = curthread;
+#endif
 	struct fuse_dispatcher fdi;
 	struct timespec uptsp;
 	int err = 0;
@@ -946,7 +949,11 @@
 		/* We are to do the check in-kernel */
 
 		if (! (facp->facc_flags & FACCESS_VA_VALID)) {
-			err = VOP_GETATTR(vp, VTOVA(vp), cred, td);
+			err = VOP_GETATTR(vp, VTOVA(vp), cred
+#if VOP_GETATTR_TAKES_THREAD
+			    , td
+#endif
+			    );
 			if (err)
 				return (err);
 			facp->facc_flags |= FACCESS_VA_VALID;
@@ -1929,7 +1936,11 @@
 		 * It will not invalidate pages which are dirty, locked, under
 		 * writeback or mapped into pagetables.") 
 		 */
+#if VOP_GETATTR_TAKES_THREAD
 		err = vinvalbuf(vp, 0, td, PCATCH, 0);
+#else
+		err = vinvalbuf(vp, 0, PCATCH, 0);
+#endif
 		fufh->flags |= FOPEN_KEEP_CACHE;
 	}
 
@@ -3005,8 +3016,11 @@
 	struct vattr *vap = ap->a_vap;
 	struct vnode *vp = ap->a_vp;
 	struct ucred *cred = ap->a_cred;
+#if VOP_GETATTR_TAKES_THREAD
 	struct thread *td = ap->a_td;
-
+#else
+	struct thread *td = curthread;
+#endif
 	int err = 0;
 	struct fuse_dispatcher fdi;
 	struct fuse_setattr_in *fsai;
