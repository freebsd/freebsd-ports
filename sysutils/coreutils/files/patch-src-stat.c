--- src/stat.c.orig	Sat Mar 22 23:32:02 2003
+++ src/stat.c	Wed Dec 17 01:35:58 2003
@@ -23,20 +23,22 @@
 #include <sys/types.h>
 #include <pwd.h>
 #include <grp.h>
-#include <unistd.h>
-#include <time.h>
-#if HAVE_SYS_STATVFS_H
+#if HAVE_SYS_STATVFS_H && HAVE_STRUCT_STATVFS_F_BASETYPE
 # include <sys/statvfs.h>
-#endif
-#if HAVE_SYS_VFS_H
+#elif HAVE_SYS_VFS_H
 # include <sys/vfs.h>
-#endif
-
+#elif HAVE_SYS_MOUNT_H && HAVE_SYS_PARAM_H
+/* NOTE: freebsd5.0 needs sys/param.h and sys/mount.h for statfs.
+   It does have statvfs.h, but shouldn't use it, since it doesn't
+   HAVE_STRUCT_STATVFS_F_BASETYPE.  So find a clean way to fix it.  */
 /* NetBSD 1.5.2 needs these, for the declaration of struct statfs. */
-#if !HAVE_SYS_STATVFS_H && !HAVE_SYS_VFS_H
-# if HAVE_SYS_MOUNT_H && HAVE_SYS_PARAM_H
-#  include <sys/param.h>
-#  include <sys/mount.h>
+# include <sys/param.h>
+# include <sys/mount.h>
+# if HAVE_NETINET_IN_H && HAVE_NFS_NFS_CLNT_H && HAVE_NFS_VFS_H
+/* Ultrix 4.4 needs these for the declaration of struct statfs.  */
+#  include <netinet/in.h>
+#  include <nfs/nfs_clnt.h>
+#  include <nfs/vfs.h>
 # endif
 #endif
 
