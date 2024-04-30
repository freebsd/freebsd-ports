--- src/3rdparty/chromium/services/device/geolocation/location_arbitrator.cc.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/services/device/geolocation/location_arbitrator.cc
@@ -190,7 +190,7 @@ LocationArbitrator::NewSystemLocationProvider() {
 
 std::unique_ptr<LocationProvider>
 LocationArbitrator::NewSystemLocationProvider() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider(main_task_runner_,
