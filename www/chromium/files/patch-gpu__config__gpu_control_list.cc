--- gpu/config/gpu_control_list.cc.orig	2016-03-05 21:33:12.769491937 +0100
+++ gpu/config/gpu_control_list.cc	2016-03-05 21:33:28.281491345 +0100
@@ -17,7 +17,11 @@
 #include "base/sys_info.h"
 #include "gpu/config/gpu_info.h"
 #include "gpu/config/gpu_util.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace gpu {
 namespace {
