--- mpifileutils/src/common/mfu_bz2_static.c.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/common/mfu_bz2_static.c
@@ -5,7 +5,9 @@
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
+#if defined(__linux__)
 #include <sys/sysinfo.h>
+#endif
 #include <string.h>
 #include <sys/time.h>
 #include <sys/resource.h>
@@ -22,6 +24,11 @@
 #include "libcircle.h"
 #include "mfu.h"
 #include "mfu_bz2.h"
+
+/* FreeBSD does not define O_LARGEFILE; large file support is implicit. */
+#ifndef O_LARGEFILE
+#define O_LARGEFILE 0
+#endif
 
 #define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
 
