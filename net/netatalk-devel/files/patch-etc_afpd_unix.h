--- etc/afpd/unix.h.orig	Sun Sep  8 23:45:56 2002
+++ etc/afpd/unix.h	Mon Sep  9 00:03:58 2002
@@ -30,7 +30,8 @@
 #if defined(TRU64)
 #define f_frsize f_fsize
 #else /* TRU64 */
-#if defined(HAVE_SYS_STATVFS_H) || defined(__svr4__)
+#if (defined(HAVE_SYS_STATVFS_H) || defined(__svr4__)) && \
+    !defined(__FreeBSD__)
 #include <sys/statvfs.h>
 #define statfs statvfs
 #else /* HAVE_SYS_STATVFS || __svr4__ */
