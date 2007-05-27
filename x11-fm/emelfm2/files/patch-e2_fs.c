--- src/filesystem/e2_fs.c.orig	Sat May 26 16:19:06 2007
+++ src/filesystem/e2_fs.c	Sat May 26 16:20:08 2007
@@ -40,7 +40,8 @@
 #include <langinfo.h>
 #include <pwd.h>
 #include <grp.h>
-#include <sys/statfs.h>
+#include <sys/param.h>
+#include <sys/mount.h>
 #ifndef MNT_LOCAL
 # include <sys/statvfs.h>
 #endif
