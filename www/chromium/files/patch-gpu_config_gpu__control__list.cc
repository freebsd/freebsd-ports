--- gpu/config/gpu_control_list.cc.orig	2017-06-05 19:03:08 UTC
+++ gpu/config/gpu_control_list.cc
@@ -11,7 +11,11 @@
 #include "base/strings/stringprintf.h"
 #include "base/sys_info.h"
 #include "gpu/config/gpu_info.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace gpu {
 namespace {
@@ -206,7 +210,7 @@ bool GpuControlList::More::GLVersionInfoMismatch(
 GpuControlList::GLType GpuControlList::More::GetDefaultGLType() {
 #if defined(OS_CHROMEOS)
   return kGLTypeGL;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kGLTypeGL;
 #elif defined(OS_MACOSX)
   return kGLTypeGL;
@@ -621,7 +625,7 @@ GpuControlList::OsType GpuControlList::GetOsType() {
   return kOsWin;
 #elif defined(OS_ANDROID)
   return kOsAndroid;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return kOsLinux;
 #elif defined(OS_MACOSX)
   return kOsMacosx;
