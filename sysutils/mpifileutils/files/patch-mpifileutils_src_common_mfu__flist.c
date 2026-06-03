--- mpifileutils/src/common/mfu_flist.c.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/common/mfu_flist.c
@@ -35,8 +35,13 @@
 #include <sys/ioctl.h>
 #include <sys/param.h>
 
+/* Linux-specific file flag ioctls live in <linux/fs.h>;
+ * not available (and not used) on FreeBSD.
+ */
+#ifdef __linux__
 #include <linux/fs.h>
 #include <linux/fiemap.h>
+#endif
 
 #include <libgen.h> /* dirname */
 #include "libcircle.h"
@@ -845,7 +850,7 @@ uint64_t mfu_flist_file_get_perm(mfu_flist bflist, uin
     return mode & (S_IRWXU | S_IRWXG | S_IRWXO);
 }
 
-#if DCOPY_USE_XATTRS
+#if defined(__linux__) && DCOPY_USE_XATTRS
 void *mfu_flist_file_get_acl(mfu_flist bflist, uint64_t idx, ssize_t *acl_size, char *type)
 {
     flist_t* flist = (flist_t*) bflist;
@@ -886,7 +891,18 @@ void *mfu_flist_file_get_acl(mfu_flist bflist, uint64_
 
     return val;
 }
+#else
+void *mfu_flist_file_get_acl(mfu_flist bflist, uint64_t idx, ssize_t *acl_size, char *type)
+{
+    (void)bflist;
+    (void)idx;
+    (void)type;
+    if (acl_size != NULL)
+        *acl_size = 0;
+    return NULL;
+}
 #endif
+
 
 uint64_t mfu_flist_file_get_uid(mfu_flist bflist, uint64_t idx)
 {
