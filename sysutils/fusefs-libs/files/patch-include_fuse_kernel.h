--- include/fuse_kernel.h.orig	Mon Oct  3 17:02:36 2005
+++ include/fuse_kernel.h	Sun Oct  9 22:05:09 2005
@@ -36,7 +36,11 @@
 
 /* This file defines the kernel interface of FUSE */
 
+#ifdef __FreeBSD__
+#include "linux_compat.h"
+#else
 #include <asm/types.h>
+#endif
 
 /** Version number of this interface */
 #define FUSE_KERNEL_VERSION 7
