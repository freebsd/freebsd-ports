--- fuse_module/fuse_vfsops.c.orig	2007-06-19 16:35:22.000000000 +0400
+++ fuse_module/fuse_vfsops.c	2008-01-20 20:39:38.000000000 +0300
@@ -23,6 +23,18 @@
 #include "fuse_session.h"
 #include "fuse_vnode.h"
 
+#if USE_PRIVILEGE_API
+#include <sys/priv.h>
+#endif
+
+/* This will do for privilege types for now */
+#ifndef PRIV_VFS_FUSE_ALLOWOTHER
+#define PRIV_VFS_FUSE_ALLOWOTHER PRIV_VFS_MOUNT_NONUSER
+#endif
+#ifndef PRIV_VFS_FUSE_MOUNT_NONUSER
+#define PRIV_VFS_FUSE_MOUNT_NONUSER PRIV_VFS_MOUNT_NONUSER
+#endif
+
 static int fuse_init_handler(struct fuse_ticket *tick, struct uio *uio);
 static void fuse_send_init(struct fuse_data *data, struct thread *td);
 static vfs_hash_cmp_t fuse_vnode_bgdrop_cmp;
@@ -207,10 +219,8 @@
 	KASSERT(fuse_useco >= 0,
 	        ("negative fuse usecount despite Giant"));
 
-	if (mp->mnt_flag & MNT_UPDATE) {
-		uprintf("fuse: updating mounts is not supported\n");
+	if (mp->mnt_flag & MNT_UPDATE)
 		return (EOPNOTSUPP);
-	}
 
 	mp->mnt_flag |= MNT_SYNCHRONOUS; 
 	/* Get the new options passed to mount */
@@ -293,10 +303,8 @@
 
 	if (fdata_kick_get(data))
 		err = ENOTCONN;
-	if (mntopts & FSESS_DAEMON_CAN_SPY && suser(td)) {
-		uprintf("only root can use \"allow_other\"\n");
-		err = EPERM;
-	}
+	if (mntopts & FSESS_DAEMON_CAN_SPY)
+	    err = priv_check(td, PRIV_VFS_FUSE_ALLOWOTHER);
 
 	slock = &data->mhierlock;
 	/* Note that sx_try_xlock returns 0 on _failure_ */
@@ -334,10 +342,9 @@
 			 */
 			err = EINVAL;
 	} else {
-		if (suser(td) &&
-	            td->td_ucred->cr_uid != data->daemoncred->cr_uid)
-			/* we are not allowed to do the first mount */
-			err = EPERM;
+		if (td->td_ucred->cr_uid != data->daemoncred->cr_uid)
+			/* are we allowed to do the first mount? */
+			err = priv_check(td, PRIV_VFS_FUSE_MOUNT_NONUSER);
 	}
 
 	if (err) {
@@ -370,7 +377,11 @@
 
 	err = getnewvnode("fuse", mp, &fuse_vnops, &rvp);
 	if (! err) {
+#if __FreeBSD_version > 800009
+		err = vn_lock(rvp, LK_EXCLUSIVE | LK_RETRY);
+#else
 		err = vn_lock(rvp, LK_EXCLUSIVE | LK_RETRY, td);
+#endif
 #if NEW_VNODES_ADJUSTED_MANUALLY
 		if (err)
 			printf("fuse4bsd: leaking vnode %p\n", rvp);
@@ -398,7 +409,11 @@
 		free(fvdat, M_FUSEVN);
 	        goto out;
 	} else
+#if __FreeBSD_version > 800009
+		VOP_UNLOCK(rvp, 0);
+#else
 		VOP_UNLOCK(rvp, 0, td);
+#endif
 
 	data->mp = mp;
 	data->mpri = FM_PRIMARY;
@@ -582,7 +597,11 @@
 
 	vp = data->rvp;
 	vref(vp);
+#if __FreeBSD_version > 800009
+	vn_lock(vp, flags | LK_RETRY);
+#else
 	vn_lock(vp, flags | LK_RETRY, td);
+#endif
 	if (vp->v_type == VNON) {
 		struct vattr va;
 
@@ -808,7 +827,11 @@
 	}
 
 #if NEW_VNODES_ADJUSTED_MANUALLY
+#if __FreeBSD_version > 800009
+	err = vn_lock(*vpp, myflags);
+#else
 	err = vn_lock(*vpp, myflags, td);
+#endif
 	if (err)
 		printf("fuse4bsd: leaking vnode %p\n", *vpp);
 	else
