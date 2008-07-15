--- dclib/core/cdir.cpp.orig	2008-07-15 00:32:51.000000000 +0200
+++ dclib/core/cdir.cpp	2008-07-15 00:33:42.000000000 +0200
@@ -30,9 +30,6 @@
 #ifdef HAVE_SYS_VFS_H
 #include <sys/vfs.h>
 #endif
-#ifdef HAVE_SYS_MOUNT_H
-#include <sys/mount.h>
-#endif
 #ifdef HAVE_SYS_PARAM_H
 #include <sys/param.h>
 #endif
