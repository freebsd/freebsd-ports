--- fs/fuse/fuse_vfsops.c.orig
+++ fs/fuse/fuse_vfsops.c
@@ -62,8 +62,8 @@
 #include <sys/errno.h>
 #include <sys/param.h>
 #include <sys/kernel.h>
-#include <sys/capsicum.h>
 #include <sys/conf.h>
+#include <sys/file.h>
 #include <sys/filedesc.h>
 #include <sys/uio.h>
 #include <sys/malloc.h>
@@ -206,7 +206,7 @@
 {
 	int err;
 
-	uint64_t mntopts, __mntopts;
+	u_int mntopts, __mntopts;
 	int max_read_set;
 	uint32_t max_read;
 	int daemon_timeout;
@@ -220,7 +220,6 @@
 	struct file *fp, *fptmp;
 	char *fspec, *subtype;
 	struct vfsoptlist *opts;
-	cap_rights_t rights;
 
 	subtype = NULL;
 	max_read_set = 0;
@@ -290,7 +289,7 @@
 
 	FS_DEBUG2G("mntopts 0x%jx\n", (uintmax_t)mntopts);
 
-	err = fget(td, fd, cap_rights_init(&rights, CAP_READ), &fp);
+	err = fget(td, fd, &fp);
 	if (err != 0) {
 		FS_DEBUG("invalid or not opened device: data=%p\n", data);
 		goto out;
@@ -459,7 +458,7 @@
 				FUSE_UNLOCK();
 				VOP_UNLOCK(*vpp, 0);
 				vrele(*vpp);
-				vrecycle(*vpp);
+				vrecycle(*vpp, curthread);
 				*vpp = data->vroot;
 			} else
 				FUSE_UNLOCK();
