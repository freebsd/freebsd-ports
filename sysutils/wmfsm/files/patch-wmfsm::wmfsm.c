--- wmfsm/wmfsm.c.orig	Sat Jul 13 13:06:35 2002
+++ wmfsm/wmfsm.c	Fri Apr  9 23:35:48 2004
@@ -54,6 +54,12 @@
 #include <sys/systeminfo.h>
 #endif /* SVR4 */
 
+#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
+#ifdef HAVE_SYS_TYPES_H
+#include <sys/types.h>
+#endif
 #ifdef HAVE_SYS_VFS_H
 #include <sys/vfs.h>
 #endif
@@ -62,12 +68,6 @@
 #endif
 #ifdef HAVE_SYS_MOUNT_H
 #include <sys/mount.h>
-#endif
-#ifdef HAVE_SYS_PARAM_H
-#include <sys/param.h>
-#endif
-#ifdef HAVE_SYS_TYPES_H
-#include <sys/types.h>
 #endif
 
 #ifdef STATFS_2_ARGUMENTS
