--- net/base/network_change_notifier.cc.orig	2020-11-13 06:36:45 UTC
+++ net/base/network_change_notifier.cc
@@ -36,7 +36,7 @@
 #include "net/base/network_change_notifier_linux.h"
 #elif defined(OS_APPLE)
 #include "net/base/network_change_notifier_mac.h"
-#elif defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#elif defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "net/base/network_change_notifier_posix.h"
 #elif defined(OS_FUCHSIA)
 #include "net/base/network_change_notifier_fuchsia.h"
@@ -249,8 +249,11 @@ std::unique_ptr<NetworkChangeNotifier> NetworkChangeNo
 #elif defined(OS_FUCHSIA)
   return std::make_unique<NetworkChangeNotifierFuchsia>(
       fuchsia::hardware::ethernet::Features());
+#elif defined(OS_BSD)
+  return std::make_unique<MockNetworkChangeNotifier>(
+      std::make_unique<SystemDnsConfigChangeNotifier>(
+          nullptr /* task_runner */, nullptr /* dns_config_service */));
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
