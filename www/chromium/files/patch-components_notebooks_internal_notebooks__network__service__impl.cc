--- components/notebooks/internal/notebooks_network_service_impl.cc.orig	2026-09-25 15:26:43 UTC
+++ components/notebooks/internal/notebooks_network_service_impl.cc
@@ -69,7 +69,7 @@ Device GetDevice() {
   return Device::kMobileAndroid;
 #elif BUILDFLAG(IS_IOS)
   return Device::kMobileIos;
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return Device::kDesktop;
 #else
   return Device::kOther;
