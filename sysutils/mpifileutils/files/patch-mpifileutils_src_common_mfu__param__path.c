--- mpifileutils/src/common/mfu_param_path.c.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/common/mfu_param_path.c
@@ -1,5 +1,23 @@
 #define _GNU_SOURCE
 
+/* Ensure POSIX faccessat(2) AT_* constants are visible on FreeBSD */
+#ifndef _POSIX_C_SOURCE
+#define _POSIX_C_SOURCE 200809L
+#endif
+
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <fcntl.h>
+#include <unistd.h>
+
+/* Fallbacks (in case headers hide these behind visibility macros) */
+#ifndef AT_FDCWD
+#define AT_FDCWD (-100)
+#endif
+#ifndef AT_SYMLINK_NOFOLLOW
+#define AT_SYMLINK_NOFOLLOW 0
+#endif
+
 #include "mfu.h"
 #include "mpi.h"
 
@@ -8,6 +26,13 @@
 #include <string.h>
 #include <stdarg.h>
 #include <errno.h>
+
+#include <sys/types.h>
+#include <sys/stat.h>
+
+#ifndef S_ISLNK
+#define S_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
+#endif
 
 #include <fcntl.h>
 #include <unistd.h>
