--- ./modules/access/file.c.orig	2010-06-22 02:05:28.000000000 -0400
+++ ./modules/access/file.c	2010-06-22 02:05:57.000000000 -0400
@@ -96,7 +96,7 @@
     if (fstatvfs (fd, &stf))
         return false;
     /* fstatvfs() is in POSIX, but MNT_LOCAL is not */
-    return !(s.f_flag & MNT_LOCAL);
+    return !(stf.f_flag & MNT_LOCAL);
 
 #elif defined (HAVE_LINUX_MAGIC_H)
     struct statfs stf;
