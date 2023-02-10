--- src/3rdparty/chromium/services/device/geolocation/location_arbitrator.cc.orig	2022-11-08 21:18:48 UTC
+++ src/3rdparty/chromium/services/device/geolocation/location_arbitrator.cc
@@ -164,7 +164,7 @@ LocationArbitrator::NewSystemLocationProvider() {
 
 std::unique_ptr<LocationProvider>
 LocationArbitrator::NewSystemLocationProvider() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider(main_task_runner_,
