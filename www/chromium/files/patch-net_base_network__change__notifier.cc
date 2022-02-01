--- net/base/network_change_notifier.cc.orig	2021-12-14 11:45:08 UTC
+++ net/base/network_change_notifier.cc
@@ -38,7 +38,7 @@
 #include "net/base/network_change_notifier_linux.h"
 #elif defined(OS_APPLE)
 #include "net/base/network_change_notifier_mac.h"
-#elif BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_ANDROID)
+#elif BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "net/base/network_change_notifier_posix.h"
 #elif defined(OS_FUCHSIA)
 #include "net/base/network_change_notifier_fuchsia.h"
@@ -314,6 +314,9 @@ std::unique_ptr<NetworkChangeNotifier> NetworkChangeNo
 #elif defined(OS_FUCHSIA)
   return std::make_unique<NetworkChangeNotifierFuchsia>(
       /*require_wlan=*/false);
+#elif defined(OS_BSD)
+  return std::make_unique<MockNetworkChangeNotifier>(
+      /*dns_config_notifier*/nullptr);
 #else
   NOTIMPLEMENTED();
   return NULL;
@@ -497,7 +500,7 @@ const char* NetworkChangeNotifier::ConnectionTypeToStr
   return kConnectionTypeNames[type];
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // static
 const internal::AddressTrackerLinux*
 NetworkChangeNotifier::GetAddressTracker() {
@@ -805,7 +808,7 @@ NetworkChangeNotifier::NetworkChangeNotifier(
   }
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 const internal::AddressTrackerLinux*
 NetworkChangeNotifier::GetAddressTrackerInternal() const {
   return NULL;
