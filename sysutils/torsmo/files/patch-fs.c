--- fs.c.orig	Thu Aug  5 19:59:50 2004
+++ fs.c	Thu Aug  5 20:01:50 2004
@@ -3,10 +3,12 @@
 #include <stdlib.h>
 #include <string.h>
 #include <errno.h>
-#include <sys/statvfs.h>
 #include <sys/types.h>
 #include <fcntl.h>
 
+#include <sys/param.h>
+#include <sys/mount.h>
+
 /* TODO: benchmark which is faster, fstatvfs() or pre-opened fd and
  * statvfs() (fstatvfs() would handle mounts I think...) */
 
@@ -15,16 +17,16 @@
 
 void update_fs_stats() {
   unsigned int i;
-  struct statvfs s;
+  struct statfs s;
   for (i=0; i<16; i++) {
     if (fs_stats[i].fd <= 0)
       break;
 
-    fstatvfs(fs_stats[i].fd, &s);
+    fstatfs(fs_stats[i].fd, &s);
 
-    fs_stats[i].size = (long long) s.f_blocks * s.f_frsize;
+    fs_stats[i].size = (long long) s.f_blocks * s.f_bsize;
     /* bfree (root) or bavail (non-roots) ? */
-    fs_stats[i].avail = (long long) s.f_bavail * s.f_frsize;
+    fs_stats[i].avail = (long long) s.f_bavail * s.f_bsize;
   }
 }
 
