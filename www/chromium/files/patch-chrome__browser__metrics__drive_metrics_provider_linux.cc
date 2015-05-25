--- chrome/browser/metrics/drive_metrics_provider_linux.cc.orig	2015-05-21 11:20:27.603865000 -0400
+++ chrome/browser/metrics/drive_metrics_provider_linux.cc	2015-05-21 11:22:16.773943000 -0400
@@ -4,7 +4,13 @@
 
 #include "chrome/browser/metrics/drive_metrics_provider.h"
 
+#if defined(OS_BSD)
+#include <sys/types.h>
+#define MAJOR(dev) major(dev)
+#define MINOR(dev) minor(dev)
+#else
 #include <linux/kdev_t.h>  // For MAJOR()/MINOR().
+#endif
 #include <sys/stat.h>
 #include <string>
 
