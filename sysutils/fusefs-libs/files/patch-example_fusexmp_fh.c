--- example/fusexmp_fh.c.orig	Tue Sep 13 21:26:12 2005
+++ example/fusexmp_fh.c	Sun Oct  9 22:05:09 2005
@@ -17,7 +17,12 @@
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
@@ -68,7 +73,11 @@
         memset(&st, 0, sizeof(st));
         st.st_ino = de->d_ino;
         st.st_mode = de->d_type << 12;
+#ifdef __FreeBSD__
+        if (filler(buf, de->d_name, &st, telldir(dp)))
+#else
         if (filler(buf, de->d_name, &st, de->d_off))
+#endif
             break;
     }
 
@@ -87,7 +96,20 @@
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
 
@@ -268,9 +290,13 @@
     int res;
     (void) path;
 
+#ifdef __FreeBSD__
+    (void) isdatasync;
+#else
     if (isdatasync)
         res = fdatasync(fi->fh);
     else
+#endif
         res = fsync(fi->fh);
     if(res == -1)
         return -errno;
