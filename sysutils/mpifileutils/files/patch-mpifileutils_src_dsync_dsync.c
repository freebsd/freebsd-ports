--- mpifileutils/src/dsync/dsync.c.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/dsync/dsync.c
@@ -24,7 +24,7 @@
 #include <stdlib.h>
 #include <mpi.h>
 #include <libcircle.h>
-#include <linux/limits.h>
+#include <limits.h>
 #include <libgen.h>
 #include <errno.h>
 #include <dtcmp.h>
@@ -32,6 +32,10 @@
 #define _XOPEN_SOURCE 600
 #include <fcntl.h>
 #include <string.h>
+
+#ifndef PATH_MAX
+#define PATH_MAX 4096
+#endif
 
 /* for bool type, true/false macros */
 #include <stdbool.h>
