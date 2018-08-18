--- gpu/config/gpu_info_collector_linux.cc.orig	2018-08-16 22:39:32.660704000 +0200
+++ gpu/config/gpu_info_collector_linux.cc	2018-08-16 22:40:00.267758000 +0200
@@ -8,7 +8,11 @@
 #include "gpu/config/gpu_info_collector.h"
 #include "gpu/config/gpu_switches.h"
 #include "third_party/angle/src/gpu_info_util/SystemInfo.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace gpu {
 
