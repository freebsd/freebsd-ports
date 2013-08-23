--- base/process/process_metrics.h.orig	2013-08-16 22:01:16.000000000 +0300
+++ base/process/process_metrics.h	2013-08-16 22:04:12.000000000 +0300
@@ -15,6 +15,13 @@
 #include "base/process.h"
 #include "base/time.h"
 
+#if defined(OS_BSD)
+#include <kvm.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#endif
+
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
 #endif
