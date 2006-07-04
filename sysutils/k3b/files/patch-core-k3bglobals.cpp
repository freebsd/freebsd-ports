--- libk3b/core/k3bglobals.cpp.orig	Fri Jun 23 19:31:55 2006
+++ libk3b/core/k3bglobals.cpp	Fri Jun 23 22:39:36 2006
@@ -41,16 +41,16 @@
 
 #include <config.h>
 #if defined(__FreeBSD__) || defined(__NetBSD__)
-#include <sys/param.h>
-#include <sys/mount.h>
-#else
-#  ifdef HAVE_SYS_STATVFS_H
-#    include <sys/statvfs.h>
-#  endif
-#  ifdef HAVE_SYS_STATFS_H
-#    include <sys/vfs.h>
-#  endif
+#  include <sys/param.h>
+#  include <sys/mount.h>
 #endif
+#ifdef HAVE_SYS_STATVFS_H
+#  include <sys/statvfs.h>
+#endif
+#ifdef HAVE_SYS_STATFS_H
+#  include <sys/vfs.h>
+#endif
+
 
 
 
