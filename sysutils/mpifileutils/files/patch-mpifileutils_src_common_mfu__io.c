--- mpifileutils/src/common/mfu_io.c.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/common/mfu_io.c
@@ -21,6 +21,12 @@
 #include "mfu.h"
 #include "mfu_errors.h"
 
+/* FreeBSD does not provide lstat64, only lstat.  Map it accordingly. */
+#ifdef __FreeBSD__
+#undef lstat64
+#define lstat64(path, buf) lstat((path), (struct stat *)(buf))
+#endif
+
 #define MFU_IO_TRIES  (5)
 #define MFU_IO_USLEEP (100)
 
