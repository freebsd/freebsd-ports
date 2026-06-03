--- mpifileutils/src/common/mfu_util.c.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/common/mfu_util.c
@@ -1,6 +1,11 @@
 /* to get nsec fields in stat structure */
 #define _GNU_SOURCE
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/param.h>
+#endif
+
 #include "mfu.h"
 #include "mpi.h"
 #include "dtcmp.h"
@@ -14,12 +19,21 @@
 #include <errno.h>
 #include <limits.h>
 
-#include <sys/types.h>
 #include <sys/stat.h>
+#include <fcntl.h>
 #include <unistd.h>
 
+#if defined(__linux__)
 #include <sys/vfs.h>
+#elif defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/mount.h>
+#endif
 
+#ifndef S_ISLNK
+#define S_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
+#endif
+
 #ifndef ULLONG_MAX
 #define ULLONG_MAX (__LONG_LONG_MAX__ * 2UL + 1UL)
 #endif
@@ -939,7 +953,7 @@ int mfu_compare_contents(
                 /* check for write error */
                 if (bytes_written < 0) {
                     MFU_LOG(MFU_LOG_ERR, "Failed to write `%s' at offset %llx (errno=%d %s)", 
-                        dst_name, (unsigned long long)off + n, strerror(errno));
+                        dst_name, (unsigned long long)off + n, errno, strerror(errno));
                     rc = -1;
                     break;
                 }
