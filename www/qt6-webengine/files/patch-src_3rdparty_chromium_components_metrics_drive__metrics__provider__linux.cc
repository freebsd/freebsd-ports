--- src/3rdparty/chromium/components/metrics/drive_metrics_provider_linux.cc.orig	2022-06-08 06:40:31 UTC
+++ src/3rdparty/chromium/components/metrics/drive_metrics_provider_linux.cc
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
 
