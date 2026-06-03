--- mpifileutils/src/common/mfu_bz2.c.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/common/mfu_bz2.c
@@ -6,7 +6,12 @@
 #include <errno.h>
 
 /* for statfs */
+#if defined(__linux__)
 #include <sys/vfs.h>
+#elif defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/mount.h>
+#endif
 
 /* for LL_SUPER_MAGIC */
 #if LUSTRE_SUPPORT
