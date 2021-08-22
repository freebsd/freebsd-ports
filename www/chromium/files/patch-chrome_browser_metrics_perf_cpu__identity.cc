--- chrome/browser/metrics/perf/cpu_identity.cc.orig	2021-07-28 07:40:29 UTC
+++ chrome/browser/metrics/perf/cpu_identity.cc
@@ -106,7 +106,7 @@ CPUIdentity GetCPUIdentity() {
   result.release =
 #if BUILDFLAG(IS_CHROMEOS_ASH)
       base::SysInfo::KernelVersion();
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
       base::SysInfo::OperatingSystemVersion();
 #else
 #error "Unsupported configuration"
