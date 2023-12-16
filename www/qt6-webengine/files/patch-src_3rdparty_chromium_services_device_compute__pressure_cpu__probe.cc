--- src/3rdparty/chromium/services/device/compute_pressure/cpu_probe.cc.orig	2022-11-30 08:12:58 UTC
+++ src/3rdparty/chromium/services/device/compute_pressure/cpu_probe.cc
@@ -29,6 +29,7 @@ std::unique_ptr<CpuProbe> CpuProbe::Create() {
 #elif BUILDFLAG(IS_MAC)
   return CpuProbeMac::Create();
 #else
+  NOTIMPLEMENTED();
   return nullptr;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 }
