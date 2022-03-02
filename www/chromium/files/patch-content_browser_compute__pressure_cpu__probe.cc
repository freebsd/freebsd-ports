--- content/browser/compute_pressure/cpu_probe.cc.orig	2022-02-28 16:54:41 UTC
+++ content/browser/compute_pressure/cpu_probe.cc
@@ -52,6 +52,7 @@ std::unique_ptr<CpuProbe> CpuProbe::Create() {
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
   return CpuProbeLinux::Create();
 #else
+  NOTIMPLEMENTED();
   return std::make_unique<NullCpuProbe>();
 #endif  // BUILDFLAG(IS_ANDROID)
 }
