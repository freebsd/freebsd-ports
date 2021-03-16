--- unsquashfs.c.orig	2019-08-29 01:58:04 UTC
+++ unsquashfs.c
@@ -32,8 +32,13 @@
 #include "stdarg.h"
 #include "fnmatch_compat.h"
 
+#ifdef __linux__
 #include <sys/sysinfo.h>
 #include <sys/sysmacros.h>
+#endif
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/resource.h>
