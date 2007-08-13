--- fuse_module/fuse_vfsops.c	Sat Jul 14 13:13:55 2007
+++ fuse_module/fuse_vfsops.c	Sat Jul 14 13:13:55 2007
@@ -23,6 +23,20 @@
 #include "fuse_session.h"
 #include "fuse_vnode.h"
 
+#if USE_PRIVILEGE_API
+#include <sys/priv.h>
+#endif
+
+
+/* This will do for privilege types for now */
+#ifndef PRIV_VFS_FUSE_ALLOWOTHER
+#define PRIV_VFS_FUSE_ALLOWOTHER PRIV_VFS_MOUNT_NONUSER
+#endif
+#ifndef PRIV_VFS_FUSE_MOUNT_NONUSER
+#define PRIV_VFS_FUSE_MOUNT_NONUSER PRIV_VFS_MOUNT_NONUSER
+#endif
+
+
 static int fuse_init_handler(struct fuse_ticket *tick, struct uio *uio);
 static void fuse_send_init(struct fuse_data *data, struct thread *td);
 static vfs_hash_cmp_t fuse_vnode_bgdrop_cmp;
@@ -207,10 +221,8 @@ fuse_mount(struct mount *mp, struct thre
 	KASSERT(fuse_useco >= 0,
 	        ("negative fuse usecount despite Giant"));
 
-	if (mp->mnt_flag & MNT_UPDATE) {
-		uprintf("fuse: updating mounts is not supported\n");
+	if (mp->mnt_flag & MNT_UPDATE)
 		return (EOPNOTSUPP);
-	}
 
 	mp->mnt_flag |= MNT_SYNCHRONOUS; 
 	/* Get the new options passed to mount */
@@ -293,10 +305,8 @@ fuse_mount(struct mount *mp, struct thre
 
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
@@ -334,10 +344,9 @@ fuse_mount(struct mount *mp, struct thre
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

