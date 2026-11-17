--- src/components/power_metrics/energy_metrics_provider.cc.orig	2026-10-18 18:43:23 UTC
+++ src/components/power_metrics/energy_metrics_provider.cc
@@ -7,7 +7,7 @@
 #include "build/build_config.h"
 #if BUILDFLAG(IS_WIN)
 #include "components/power_metrics/energy_metrics_provider_win.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/power_metrics/energy_metrics_provider_linux.h"
 #endif  // BUILDFLAG(IS_WIN)
 
@@ -20,7 +20,7 @@ EnergyMetricsProvider::~EnergyMetricsPro
 std::unique_ptr<EnergyMetricsProvider> EnergyMetricsProvider::Create() {
 #if BUILDFLAG(IS_WIN)
   return EnergyMetricsProviderWin::Create();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return EnergyMetricsProviderLinux::Create();
 #else
   return nullptr;
