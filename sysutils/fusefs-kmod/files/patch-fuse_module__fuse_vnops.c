--- fuse_module/fuse_vnops.c.orig	2008-02-05 00:25:57.000000000 -0500
+++ fuse_module/fuse_vnops.c	2008-10-29 19:21:51.000000000 -0400
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
@@ -871,7 +874,11 @@
 fuse_access(ap)
 	struct vop_access_args /* {
 		struct vnode *a_vp;
+#if VOP_ACCESS_TAKES_ACCMODE_T
+		accmode_t a_accmode;
+#else
 		int a_mode;
+#endif
 		struct ucred *a_cred;
 		struct thread *a_td;
 	} */ *ap;
@@ -886,7 +893,13 @@
 	else
 		facp.facc_flags |= FACCESS_DO_ACCESS;
 
-	return fuse_access_i(vp, ap->a_mode, ap->a_cred, ap->a_td, &facp);
+	return fuse_access_i(vp,
+#if VOP_ACCESS_TAKES_ACCMODE_T
+	    ap->a_accmode,
+#else
+	    ap->a_mode,
+#endif
+	    ap->a_cred, ap->a_td, &facp);
 }
 
 /*
@@ -946,7 +959,11 @@
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
@@ -1929,7 +1946,11 @@
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
 
@@ -3005,8 +3026,11 @@
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
