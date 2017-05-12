--- include/freebsd.h.orig	2015-07-24 04:28:04 UTC
+++ include/freebsd.h
@@ -37,10 +37,14 @@
 #define ftruncate64	ftruncate
 #define lseek64		lseek
 #define stat64		stat
+#define lstat64		lstat
 #define pwrite64	pwrite
 #define pread64		pread
 #define fdatasync	fsync
 #define memalign(a,sz)	valloc(sz)
+#define nftw64		nftw
+#define statvfs64	statvfs
+#define posix_fadvise64	posix_fadvise
 
 #define constpp	char * const *
 
