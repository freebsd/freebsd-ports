--- fuse_module/fuse_vnops.c.orig	2007-06-19 16:35:22.000000000 +0400
+++ fuse_module/fuse_vnops.c	2008-01-20 20:45:28.000000000 +0300
@@ -42,6 +42,10 @@
 #include "fuse_vnode.h"
 #include "fuse_io.h"
 
+#if USE_PRIVILEGE_API
+#include <sys/priv.h>
+#endif
+
 /* function prototype for iterators over filehandles (of a vp) */
 typedef int fuse_metrics_t(struct vnode *vp, struct thread *td,
                            struct ucred *cred, struct fuse_filehandle *fufh,
@@ -63,7 +67,9 @@
 #define FACCESS_CHOWN      0x08 /* do permission check for owner changing */
 #define FACCESS_NOCHECKSPY 0x10 /* don't check if daemon is allowed to spy on
                                    user */
-#define FACCESS_XQUERIES FACCESS_STICKY | FACCESS_CHOWN
+#define FACCESS_SETGID     0x12 /* do permission check for setting setgid flag */
+
+#define FACCESS_XQUERIES FACCESS_STICKY | FACCESS_CHOWN | FACCESS_SETGID
 
 #define FVP_ACCESS_NOOP   0x01 /* vnode based control flag for doing access check */
 
@@ -855,6 +861,7 @@
 
 /*
  * Attribute caching hasn't yet been implemented.
+ * [... Update: it _has been_ implemented.]
  * However, within one function we don't wanna query attributes
  * several times. Now it's enough pull the attributes once, and throw
  * it into the following routine with various modes.
@@ -929,12 +936,16 @@
 			    mode == VWRITE) {
 				if (cred->cr_uid != facp->xuid &&
 				    cred->cr_uid != VTOVA(vp)->va_uid)
-					    err = suser_cred(cred, SUSER_ALLOWJAIL);
+	    				err = priv_check_cred(cred,
+					                      PRIV_VFS_ADMIN,
+					                      0);
 			}
 			/*
 			 * We return here because this flags is exlusive
 			 * with the others
 			 */
+			KASSERT(facp->facc_flags == FACCESS_STICKY,
+			        ("sticky access check comes in mixed"));
 			return (err);
 		}
 
@@ -947,10 +958,21 @@
 			    (cred->cr_gid != facp->xgid &&
 			         facp->xgid != (gid_t)VNOVAL &&
 			         ! groupmember(facp->xgid, cred)))
-				err = suser_cred(cred, SUSER_ALLOWJAIL);
-			return (err);
+				err = priv_check_cred(cred, PRIV_VFS_CHOWN, 0);
+			if (err)
+				return (err);
 		}
 
+		if (facp->facc_flags & FACCESS_SETGID) {
+			gid_t sgid = facp->xgid;
+
+			if (sgid == (gid_t)VNOVAL)
+				sgid = VTOVA(vp)->va_gid;
+
+			if (! groupmember(sgid, cred))
+				err = priv_check_cred(cred, PRIV_VFS_SETGID, 0);
+			return (err);
+		}
 
 	} else {
 #if FUSE_HAS_ACCESS
@@ -1234,7 +1256,13 @@
 		 */
 		if (nameiop == RENAME && wantparent && islastcn) {
 			DEBUG("something to rename...\n");
-			if ((err = fuse_access_i(dvp, VWRITE, cred, td, &facp)))
+
+			facp.xuid = fattr->uid;
+			facp.facc_flags |= FACCESS_STICKY;
+			err = fuse_access_i(dvp, VWRITE, cred, td, &facp);
+			facp.facc_flags &= ~FACCESS_XQUERIES;
+
+			if (err)
 				goto out;
 
 			/*
@@ -1270,12 +1298,20 @@
 				 * If doing dotdot, we unlock dvp for vget time
 				 * to conform lock order regulations.
 				 */
+#if __FreeBSD_version > 800009
+				VOP_UNLOCK(dvp, 0);
+#else
 				VOP_UNLOCK(dvp, 0, td);
+#endif
 			err = fuse_vget_i(dvp->v_mount, td, nid,
 			                  IFTOVT(fattr->mode), &vp, VG_NORMAL,
 			                  parentid);
 			if (flags & ISDOTDOT)
+#if __FreeBSD_version > 800009
+				vn_lock(dvp, LK_EXCLUSIVE | LK_RETRY);
+#else
 				vn_lock(dvp, LK_EXCLUSIVE | LK_RETRY, td);
+#endif
 			if (err)
 				goto out;
 			*vpp = vp;
@@ -1540,7 +1576,11 @@
 	cache_attrs(vp, feo);
 
 try_insert:
+#if __FreeBSD_version > 800009
+	VOP_UNLOCK(vp, 0);
+#else
 	VOP_UNLOCK(vp, 0, td);
+#endif
 	/*
 	 * We can't let the vnode being vput() here, the caller wants
 	 * that do by herself.
@@ -1555,7 +1595,11 @@
 
 #if NEW_VNODES_ADJUSTED_MANUALLY
 	if (! err) {
+#if __FreeBSD_version > 800009
+		err = vn_lock(vp, LK_EXCLUSIVE | LK_RETRY);
+#else
 		err = vn_lock(vp, LK_EXCLUSIVE | LK_RETRY, td);
+#endif
 		if (err)
 			printf("fuse4bsd: leaking vnode %p\n", vp);
 		else {
@@ -1928,7 +1972,11 @@
 	if (! _file_is_fat(fp))
 		panic("non-fat file passed to close routine");
 
+#if __FreeBSD_version > 800009
+	vn_lock(vp, LK_EXCLUSIVE | LK_RETRY);
+#else
 	vn_lock(vp, LK_EXCLUSIVE | LK_RETRY, td);
+#endif
 
 	if (_file_is_bad(fp)) {
 		DEBUG2G("fp %p, vnode #%llu: went bad, giving up\n",
@@ -2371,8 +2419,11 @@
 	 */
 	if ((err = getnewvnode("fuse", dvp->v_mount, &fuse_vnops, vpp)))
 		return (err);
-
+#if __FreeBSD_version > 800009
+	if ((err = vn_lock(*vpp, LK_EXCLUSIVE | LK_RETRY))) {
+#else
 	if ((err = vn_lock(*vpp, LK_EXCLUSIVE | LK_RETRY, curthread))) {
+#endif
 #if NEW_VNODES_ADJUSTED_MANUALLY
 		printf("fuse4bsd: leaking vnode %p\n", *vpp);
 #endif
@@ -2719,7 +2770,11 @@
 	 * No LK_RETRY. See discussion in thread
 	 * http://thread.gmane.org/gmane.os.dragonfly-bsd.kernel/8952/focus=8964
 	 */
+#if __FreeBSD_version > 800009
+	err = vn_lock(fvp, LK_EXCLUSIVE);
+#else
 	err = vn_lock(fvp, LK_EXCLUSIVE, td);
+#endif
 	if (err)
 		goto out;
 
@@ -2730,7 +2785,11 @@
 		if ((fcnp->cn_namelen == 1 && fcnp->cn_nameptr[0] == '.')
 			|| fdvp == fvp
 			|| ((fcnp->cn_flags | tcnp->cn_flags) & ISDOTDOT)) {
+#if __FreeBSD_version > 800009
+			VOP_UNLOCK(fvp, 0);
+#else
 			VOP_UNLOCK(fvp, 0, td);
+#endif
 			err = EINVAL;
 			goto out;
 		}
@@ -2748,7 +2807,11 @@
 	 */
 	err = fuse_access_i(fvp, VWRITE, tcnp->cn_cred, tcnp->cn_thread, &facp);
 	fnid = VTOI(fvp);
+#if __FreeBSD_version > 800009
+	VOP_UNLOCK(fvp, 0);
+#else
 	VOP_UNLOCK(fvp, 0, td);
+#endif
 	if (err)
 		goto out;
 
@@ -2948,8 +3011,14 @@
 	}
 
 	if (vap->va_mode != (mode_t)VNOVAL) {
+#if _DEBUG
 		if (vap->va_mode & S_IFMT)
-			DEBUG("fuse_setattr -- weird: format bits in mode field, 0%o\n", vap->va_mode);
+			DEBUG("fuse_setattr -- weird: "
+			      "format bits in mode field, 0%o\n",
+			      vap->va_mode);
+#endif
+		if (vap->va_mode & S_ISGID)
+			facp.facc_flags |= FACCESS_SETGID;
 		fsai->FUSEATTR(mode) = vap->va_mode & ALLPERMS;
 		fsai->valid |= FATTR_MODE;
 	}
