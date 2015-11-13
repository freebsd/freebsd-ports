--- components/metrics/drive_metrics_provider_linux.cc.orig	2015-10-14 16:34:04.903957000 +0200
+++ components/metrics/drive_metrics_provider_linux.cc	2015-10-14 16:34:35.113096000 +0200
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
 
