--- src/3rdparty/chromium/net/base/network_change_notifier.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/net/base/network_change_notifier.cc
@@ -39,7 +39,7 @@
 #include "net/base/network_change_notifier_linux.h"
 #elif BUILDFLAG(IS_APPLE)
 #include "net/base/network_change_notifier_mac.h"
-#elif BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "net/base/network_change_notifier_posix.h"
 #elif BUILDFLAG(IS_FUCHSIA)
 #include "net/base/network_change_notifier_fuchsia.h"
@@ -331,6 +331,9 @@ std::unique_ptr<NetworkChangeNotifier> NetworkChangeNo
 #elif BUILDFLAG(IS_FUCHSIA)
   return std::make_unique<NetworkChangeNotifierFuchsia>(
       /*require_wlan=*/false);
+#elif BUILDFLAG(IS_BSD)
+  return std::make_unique<MockNetworkChangeNotifier>(
+      /*dns_config_notifier*/nullptr);
 #else
   NOTIMPLEMENTED();
   return NULL;
