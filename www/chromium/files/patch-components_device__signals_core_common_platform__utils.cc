--- components/device_signals/core/common/platform_utils.cc.orig	2026-09-25 15:26:43 UTC
+++ components/device_signals/core/common/platform_utils.cc
@@ -78,7 +78,7 @@ std::vector<std::string> GetMacAddresses() {
     mac_addresses = test_addresses.value();
   } else {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     mac_addresses = internal::GetMacAddressesImpl();
 #endif
   }
