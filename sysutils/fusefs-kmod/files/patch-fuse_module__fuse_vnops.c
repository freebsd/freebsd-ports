--- fuse_module/fuse_vnops.c.orig	2008-09-26 13:08:03.000000000 -0400
+++ fuse_module/fuse_vnops.c	2008-09-26 13:14:36.000000000 -0400
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
@@ -3005,8 +3012,11 @@
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
