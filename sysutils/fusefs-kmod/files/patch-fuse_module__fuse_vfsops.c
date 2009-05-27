--- fuse_module/fuse_vfsops.c.orig	2008-02-05 00:25:57.000000000 -0500
+++ fuse_module/fuse_vfsops.c	2009-05-13 18:54:01.000000000 -0400
@@ -18,6 +18,7 @@
 #include <sys/namei.h>
 #include <sys/mount.h>
 #include <sys/sysctl.h>
+#include <sys/fcntl.h>
 
 #include "fuse.h"
 #include "fuse_session.h"
@@ -213,8 +214,14 @@
  * Mount system call
  */
 static int
+#if VFSOPS_TAKES_THREAD
 fuse_mount(struct mount *mp, struct thread *td)
 {
+#else
+fuse_mount(struct mount *mp)
+{
+	struct thread *td = curthread;
+#endif
 	int err = 0;
 	size_t len;
 	char *fspec, *subtype = NULL;
@@ -529,8 +536,14 @@
  * Unmount system call
  */
 static int
+#if VFSOPS_TAKES_THREAD
 fuse_unmount(struct mount *mp, int mntflags, struct thread *td)
 {
+#else
+fuse_unmount(struct mount *mp, int mntflags)
+{
+	struct thread *td = curthread;
+#endif
 	int flags = 0, err = 0;
 	struct fuse_data *data;
 	struct fuse_secondary_data *fsdat = NULL;
@@ -633,8 +646,14 @@
 
 /* stolen from portalfs */
 static int
+#if VFSOPS_TAKES_THREAD
 fuse_root(struct mount *mp, int flags, struct vnode **vpp, struct thread *td)
 {
+#else
+fuse_root(struct mount *mp, int flags, struct vnode **vpp)
+{
+	struct thread *td = curthread;
+#endif
 	/*
 	 * Return locked reference to root.
 	 */
@@ -650,7 +669,11 @@
 		data = fsdat->master;
 		sx_slock(&data->mhierlock);
 		if (data->mpri == FM_PRIMARY)
-			err = fuse_root(data->mp, flags, vpp, td);
+			err = fuse_root(data->mp, flags, vpp
+#if VFSOPS_TAKES_THREAD
+			    , td
+#endif
+			    );
 		else
 			err = ENXIO;
 		sx_sunlock(&data->mhierlock);
@@ -667,7 +690,11 @@
 	if (vp->v_type == VNON) {
 		struct vattr va;
 
-		(void)VOP_GETATTR(vp, &va, td->td_ucred, td);
+		(void)VOP_GETATTR(vp, &va, td->td_ucred
+#if VOP_GETATTR_TAKES_THREAD
+		    , td
+#endif
+		);
 	}
 	*vpp = vp;
 #if _DEBUG2G
@@ -678,8 +705,14 @@
 }
 
 static int
+#if VFSOPS_TAKES_THREAD
 fuse_statfs(struct mount *mp, struct statfs *sbp, struct thread *td)
 {
+#else
+fuse_statfs(struct mount *mp, struct statfs *sbp)
+{
+	struct thread *td = curthread;
+#endif
 	struct fuse_dispatcher fdi;
 	struct fuse_statfs_out *fsfo;
 	struct fuse_data *data;
@@ -696,7 +729,11 @@
 
 		sx_slock(&data->mhierlock);
 		if (data->mpri == FM_PRIMARY)
-			err = fuse_statfs(data->mp, sbp, td);
+			err = fuse_statfs(data->mp, sbp
+#if VFSOPS_TAKES_THREAD
+			    , td
+#endif
+			    );
 		else
 			err = ENXIO;
 		sx_sunlock(&data->mhierlock);
@@ -794,7 +831,11 @@
 	if (nodeid == FUSE_ROOT_ID) {
 		if (parentid != FUSE_NULL_ID)
 			return (ENOENT);
-		err = VFS_ROOT(mp, myflags, vpp, td);
+		err = VFS_ROOT(mp, myflags, vpp
+#if VFSOPS_TAKES_THREAD
+		    , td
+#endif
+		    );
 		if (err)
 			return (err);
 		KASSERT(*vpp, ("we neither err'd nor found the root node"));
