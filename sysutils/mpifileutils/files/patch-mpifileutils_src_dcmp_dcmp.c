--- mpifileutils/src/dcmp/dcmp.c.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/dcmp/dcmp.c
@@ -4,7 +4,12 @@
 #include <stdlib.h>
 #include <mpi.h>
 #include <libcircle.h>
+#ifdef __linux__
 #include <linux/limits.h>
+#elif defined(__FreeBSD__)
+#include <limits.h>
+#include <sys/param.h>
+#endif
 #include <libgen.h>
 #include <errno.h>
 #include <dtcmp.h>
