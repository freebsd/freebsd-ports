--- components/system_cpu/cpu_probe.cc.orig	2025-08-07 06:57:29 UTC
+++ components/system_cpu/cpu_probe.cc
@@ -20,6 +20,10 @@
 #include "components/system_cpu/cpu_probe_mac.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
+#if BUILDFLAG(IS_BSD)
+#include "base/notimplemented.h"
+#endif
+
 namespace system_cpu {
 
 // static
@@ -30,6 +34,9 @@ std::unique_ptr<CpuProbe> CpuProbe::Create() {
   return CpuProbeWin::Create();
 #elif BUILDFLAG(IS_MAC)
   return CpuProbeMac::Create();
+#elif BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return nullptr;
 #else
   return nullptr;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
