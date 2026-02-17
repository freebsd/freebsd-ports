--- chrome/browser/metrics/perf/cpu_identity.cc.orig	2026-02-15 10:01:45 UTC
+++ chrome/browser/metrics/perf/cpu_identity.cc
@@ -155,7 +155,7 @@ CPUIdentity GetCPUIdentity() {
   result.release =
 #if BUILDFLAG(IS_CHROMEOS)
       base::SysInfo::KernelVersion();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::SysInfo::OperatingSystemVersion();
 #else
 #error "Unsupported configuration"
