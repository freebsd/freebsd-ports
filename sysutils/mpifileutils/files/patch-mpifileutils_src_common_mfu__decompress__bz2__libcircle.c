--- mpifileutils/src/common/mfu_decompress_bz2_libcircle.c.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/common/mfu_decompress_bz2_libcircle.c
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
