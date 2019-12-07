--- libraries/liblmdb/mdb.c.orig	2019-07-23 14:46:22 UTC
+++ libraries/liblmdb/mdb.c
@@ -124,7 +124,10 @@ typedef SSIZE_T	ssize_t;
 #include <resolv.h>	/* defines BYTE_ORDER on HPUX and Solaris */
 #endif
 
-#if defined(__APPLE__) || defined (BSD) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__)
+#  define MDB_USE_POSIX_MUTEX	1
+#  define MDB_USE_ROBUST	1
+#elif defined(__APPLE__) || defined (BSD) || defined(__FreeBSD_kernel__)
 # define MDB_USE_POSIX_SEM	1
 # define MDB_FDATASYNC		fsync
 #elif defined(ANDROID)
