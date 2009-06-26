--- src/main.c.orig	2009-06-25 05:11:08.000000000 +0400
+++ src/main.c	2009-06-25 05:23:57.000000000 +0400
@@ -755,7 +755,7 @@
     return -errno;
 }
 
-#if _POSIX_SYNCHRONIZED_IO + 0 > 0
+#if _POSIX_SYNCHRONIZED_IO + 0 > 0 || defined(__FreeBSD__)
 #undef HAVE_FDATASYNC
 #else
 #define HAVE_FDATASYNC 1
