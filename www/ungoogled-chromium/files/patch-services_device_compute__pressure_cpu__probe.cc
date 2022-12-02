--- services/device/compute_pressure/cpu_probe.cc.orig	2022-12-02 17:56:32 UTC
+++ services/device/compute_pressure/cpu_probe.cc
@@ -29,6 +29,7 @@ std::unique_ptr<CpuProbe> CpuProbe::Create() {
 #elif BUILDFLAG(IS_MAC)
   return CpuProbeMac::Create();
 #else
+  NOTIMPLEMENTED();
   return nullptr;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 }
