--- chrome/browser/metrics/perf/cpu_identity.cc.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/metrics/perf/cpu_identity.cc
@@ -146,7 +146,7 @@ CPUIdentity GetCPUIdentity() {
   result.release =
 #if BUILDFLAG(IS_CHROMEOS)
       base::SysInfo::KernelVersion();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::SysInfo::OperatingSystemVersion();
 #else
 #error "Unsupported configuration"
