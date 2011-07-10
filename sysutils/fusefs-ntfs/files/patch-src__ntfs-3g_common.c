--- src/ntfs-3g_common.9	2011-04-23 09:17:21.000000000 +0200
+++ src/ntfs-3g_common.c	2011-04-24 08:24:33.000000000 +0200
@@ -32,6 +32,10 @@
 #include <string.h>
 #endif

+#ifdef HAVE_LIMITS_H
+#include <limits.h>
+#endif
+
 #ifdef HAVE_ERRNO_H
 #include <errno.h>
 #endif
--- src/ntfs-3g_common.c.ref	2011-04-23 08:25:28.000000000 +0200
+++ src/ntfs-3g_common.c	2011-04-23 08:32:16.000000000 +0200
@@ -58,8 +58,6 @@

 static const char nf_ns_alt_xattr_efsinfo[] = "user.ntfs.efsinfo";

-#ifdef HAVE_SETXATTR
-
 static const char def_opts[] = "allow_other,nonempty,";

 	/*
@@ -573,6 +571,8 @@
 	return 0;
 }

+#ifdef HAVE_SETXATTR
+
 int ntfs_fuse_listxattr_common(ntfs_inode *ni, ntfs_attr_search_ctx *actx,
 			char *list, size_t size, BOOL prefixing)
 {
