--- fs/fuse/fuse_vfsops.c.orig	2014-03-16 12:55:57.000000000 +0200
+++ fs/fuse/fuse_vfsops.c	2014-12-02 16:02:35.879606170 +0200
@@ -62,7 +62,7 @@
 #include <sys/errno.h>
 #include <sys/param.h>
 #include <sys/kernel.h>
-#include <sys/capsicum.h>
+#include <sys/capability.h>
 #include <sys/conf.h>
 #include <sys/filedesc.h>
 #include <sys/uio.h>
@@ -113,13 +113,24 @@
 	.vfs_statfs = fuse_vfsop_statfs,
 };
 
+#ifdef SYSCTL_NULL_INT_PTR
+SYSCTL_INT(_vfs_fuse, OID_AUTO, init_backgrounded, CTLFLAG_RD,
+    SYSCTL_NULL_INT_PTR, 1, "indicate async handshake");
+#else
 SYSCTL_INT(_vfs_fuse, OID_AUTO, init_backgrounded, CTLFLAG_RD,
     0, 1, "indicate async handshake");
+#endif // SYSCTL_NULL_INT_PTR
 static int fuse_enforce_dev_perms = 0;
 
+#ifdef SYSCTL_NULL_INT_PTR
+SYSCTL_INT(_vfs_fuse, OID_AUTO, enforce_dev_perms, CTLFLAG_RW,
+    &fuse_enforce_dev_perms, 0,
+    "enforce fuse device permissions for secondary mounts");
+#else
 SYSCTL_LONG(_vfs_fuse, OID_AUTO, enforce_dev_perms, CTLFLAG_RW,
     &fuse_enforce_dev_perms, 0,
     "enforce fuse device permissions for secondary mounts");
+#endif // SYSCTL_NULL_INT_PTR
 static unsigned sync_unmount = 1;
 
 SYSCTL_UINT(_vfs_fuse, OID_AUTO, sync_unmount, CTLFLAG_RW,
@@ -220,7 +231,6 @@
 	struct file *fp, *fptmp;
 	char *fspec, *subtype;
 	struct vfsoptlist *opts;
-	cap_rights_t rights;
 
 	subtype = NULL;
 	max_read_set = 0;
@@ -290,7 +300,7 @@
 
 	FS_DEBUG2G("mntopts 0x%jx\n", (uintmax_t)mntopts);
 
-	err = fget(td, fd, cap_rights_init(&rights, CAP_READ), &fp);
+	err = fget(td, fd, CAP_READ, &fp);
 	if (err != 0) {
 		FS_DEBUG("invalid or not opened device: data=%p\n", data);
 		goto out;
@@ -459,7 +469,7 @@
 				FUSE_UNLOCK();
 				VOP_UNLOCK(*vpp, 0);
 				vrele(*vpp);
-				vrecycle(*vpp);
+				vrecycle(*vpp, curthread);
 				*vpp = data->vroot;
 			} else
 				FUSE_UNLOCK();
