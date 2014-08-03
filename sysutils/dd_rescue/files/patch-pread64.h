--- pread64.h.orig	2014-06-29 00:37:49.000000000 +0900
+++ pread64.h	2014-06-29 00:39:50.000000000 +0900
@@ -94,7 +94,7 @@
 {
 	return pread(fd, buf, sz, off);
 }
-static inline ssize_t pwrite(int fd, const void *buf, size_t sz, loff_t off)
+static inline ssize_t pwrite64(int fd, const void *buf, size_t sz, loff_t off)
 {
 	return pwrite(fd, buf, sz, off);
 }
