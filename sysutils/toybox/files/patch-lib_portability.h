--- lib/portability.h.orig	2021-06-01 14:59:57 UTC
+++ lib/portability.h
@@ -217,7 +217,7 @@ int posix_fallocate(int, off_t, off_t);
 #include <xlocale.h>
 #endif
 
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 static inline long statfs_bsize(struct statfs *sf) { return sf->f_iosize; }
 static inline long statfs_frsize(struct statfs *sf) { return sf->f_bsize; }
 #else
