--- src/3rdparty/chromium/gpu/config/gpu_control_list.cc.orig	2017-01-26 00:49:14 UTC
+++ src/3rdparty/chromium/gpu/config/gpu_control_list.cc
@@ -19,7 +19,11 @@
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
@@ -1154,7 +1158,7 @@ GpuControlList::GpuControlListEntry::GLT
 GpuControlList::GpuControlListEntry::GetDefaultGLType() {
 #if defined(OS_CHROMEOS)
   return kGLTypeGL;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kGLTypeGL;
 #elif defined(OS_MACOSX)
   return kGLTypeGL;
@@ -1606,7 +1610,7 @@ GpuControlList::OsType GpuControlList::G
   return kOsWin;
 #elif defined(OS_ANDROID)
   return kOsAndroid;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kOsLinux;
 #elif defined(OS_MACOSX)
   return kOsMacosx;
