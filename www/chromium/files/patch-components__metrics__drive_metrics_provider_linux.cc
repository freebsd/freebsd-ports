--- components/metrics/drive_metrics_provider_linux.cc.orig	2015-10-14 08:11:50.411251000 -0400
+++ components/metrics/drive_metrics_provider_linux.cc	2015-10-14 08:12:35.355093000 -0400
@@ -4,7 +4,13 @@
 
 #include "components/metrics/drive_metrics_provider.h"
 
+#if defined(OS_BSD)
+#include <sys/types.h>
+#define MAJOR(dev) major(dev)
+#define MINOR(dev) minor(dev)
+#else
 #include <linux/kdev_t.h>  // For MAJOR()/MINOR().
+#endif
 #include <sys/stat.h>
 #include <string>
 
