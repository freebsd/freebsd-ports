--- fs/fuse/fuse_vfsops.c.orig
+++ fs/fuse/fuse_vfsops.c
@@ -62,7 +62,7 @@ __FBSDID("$FreeBSD$");
 #include <sys/errno.h>
 #include <sys/param.h>
 #include <sys/kernel.h>
-#include <sys/capsicum.h>
+#include <sys/capability.h>
 #include <sys/conf.h>
 #include <sys/filedesc.h>
 #include <sys/uio.h>
@@ -220,7 +220,6 @@ fuse_vfsop_mount(struct mount *mp)
 	struct file *fp, *fptmp;
 	char *fspec, *subtype;
 	struct vfsoptlist *opts;
-	cap_rights_t rights;
 
 	subtype = NULL;
 	max_read_set = 0;
@@ -290,7 +289,7 @@ fuse_vfsop_mount(struct mount *mp)
 
 	FS_DEBUG2G("mntopts 0x%jx\n", (uintmax_t)mntopts);
 
-	err = fget(td, fd, cap_rights_init(&rights, CAP_READ), &fp);
+	err = fget(td, fd, CAP_READ, &fp);
 	if (err != 0) {
 		FS_DEBUG("invalid or not opened device: data=%p\n", data);
 		goto out;
@@ -459,7 +458,7 @@ fuse_vfsop_root(struct mount *mp, int lkflags, struct vnode **vpp)
 				FUSE_UNLOCK();
 				VOP_UNLOCK(*vpp, 0);
 				vrele(*vpp);
-				vrecycle(*vpp);
+				vrecycle(*vpp, curthread);
 				*vpp = data->vroot;
 			} else
 				FUSE_UNLOCK();
