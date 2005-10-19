--- example/fusexmp.c.orig	Tue Sep 13 21:26:12 2005
+++ example/fusexmp.c	Sun Oct  9 22:05:09 2005
@@ -20,7 +20,12 @@
 #include <fcntl.h>
 #include <dirent.h>
 #include <errno.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/mount.h>
+#else
 #include <sys/statfs.h>
+#endif
 #ifdef HAVE_SETXATTR
 #include <sys/xattr.h>
 #endif
@@ -79,7 +84,20 @@
 {
     int res;
 
+#ifndef __FreeBSD__
     res = mknod(path, mode, rdev);
+#else
+    if (rdev)
+        res = mknod(path, mode, rdev);
+    else if (mode & S_IFIFO)
+        res = mkfifo(path, mode);
+    else {
+        res = open(path, O_CREAT | O_TRUNC | O_WRONLY, mode);
+        if (res >= 0)
+            res = close(res);
+    }
+#endif
+
     if(res == -1)
         return -errno;
 
