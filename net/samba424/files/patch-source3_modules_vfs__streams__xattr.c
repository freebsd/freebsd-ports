--- source3/modules/vfs_streams_xattr.c.orig	2026-07-23 20:25:05 UTC
+++ source3/modules/vfs_streams_xattr.c
@@ -22,6 +22,13 @@
  */
 
 #include "includes.h"
+#ifndef ENODATA
+#ifdef ENOATTR
+#define ENODATA ENOATTR
+#else
+#define ENODATA ENOENT
+#endif
+#endif
 #include "smbd/smbd.h"
 #include "system/filesys.h"
 #include "lib/util/tevent_unix.h"
