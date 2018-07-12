--- src/utils/os_unix.c.orig	2015-09-27 19:02:05 UTC
+++ src/utils/os_unix.c
@@ -23,6 +23,10 @@
 #include <mach/mach_time.h>
 #endif /* __MACH__ */
 
+#ifdef __FreeBSD__
+#define fdatasync fsync
+#endif
+
 #include "os.h"
 #include "common.h"
 
