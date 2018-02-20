--- gpu/config/gpu_control_list.cc.orig	2017-12-15 02:04:19.000000000 +0100
+++ gpu/config/gpu_control_list.cc	2017-12-24 16:25:45.151636000 +0100
@@ -16,7 +16,11 @@
 #include "base/values.h"
 #include "build/build_config.h"
 #include "gpu/config/gpu_info.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace gpu {
 namespace {
@@ -211,7 +215,7 @@
 GpuControlList::GLType GpuControlList::More::GetDefaultGLType() {
 #if defined(OS_CHROMEOS)
   return kGLTypeGL;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kGLTypeGL;
 #elif defined(OS_MACOSX)
   return kGLTypeGL;
@@ -644,7 +648,7 @@
   return kOsAndroid;
 #elif defined(OS_FUCHSIA)
   return kOsFuchsia;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kOsLinux;
 #elif defined(OS_MACOSX)
   return kOsMacosx;
