--- pread64.h.orig	2015-04-15 08:56:38 UTC
+++ pread64.h
@@ -94,7 +94,7 @@ static inline ssize_t pread64(int fd, vo
 {
 	return pread(fd, buf, sz, off);
 }
-static inline ssize_t pwrite(int fd, const void *buf, size_t sz, loff_t off)
+static inline ssize_t pwrite64(int fd, const void *buf, size_t sz, loff_t off)
 {
 	return pwrite(fd, buf, sz, off);
 }
