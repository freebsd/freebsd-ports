--- unsquashfs.c.orig
+++ unsquashfs.c
@@ -31,7 +31,14 @@
 #include "unsquashfs_info.h"
 #include "stdarg.h"
 
+#ifdef __linux__
 #include <sys/sysinfo.h>
+#endif
+
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
+
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/resource.h>
