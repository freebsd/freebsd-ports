--- gpu/config/gpu_control_list.cc.orig	2021-04-14 18:41:04 UTC
+++ gpu/config/gpu_control_list.cc
@@ -18,7 +18,11 @@
 #include "build/build_config.h"
 #include "build/chromeos_buildflags.h"
 #include "gpu/config/gpu_util.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif // defined(OS_BSD)
 
 namespace gpu {
 namespace {
@@ -276,7 +280,7 @@ bool GpuControlList::More::GLVersionInfoMismatch(
 GpuControlList::GLType GpuControlList::More::GetDefaultGLType() {
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   return kGLTypeGL;
-#elif (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#elif (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_OPENBSD)
   return kGLTypeGL;
 #elif defined(OS_MAC)
@@ -783,7 +787,7 @@ GpuControlList::OsType GpuControlList::GetOsType() {
   return kOsAndroid;
 #elif defined(OS_FUCHSIA)
   return kOsFuchsia;
-#elif (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#elif (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_OPENBSD)
   return kOsLinux;
 #elif defined(OS_MAC)
