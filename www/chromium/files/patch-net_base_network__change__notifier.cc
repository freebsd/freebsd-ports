--- net/base/network_change_notifier.cc.orig	2022-02-07 13:39:41 UTC
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
@@ -303,9 +303,13 @@ std::unique_ptr<NetworkChangeNotifier> NetworkChangeNo
   // service in a separate process.
   return std::make_unique<NetworkChangeNotifierPosix>(initial_type,
                                                       initial_subtype);
-#elif BUILDFLAG(IS_CHROMEOS_ASH)
+#elif BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_BSD)
+#if !defined(OS_BSD)
   return std::make_unique<NetworkChangeNotifierPosix>(initial_type,
                                                       initial_subtype);
+#else
+  return NULL;
+#endif
 #elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
   return std::make_unique<NetworkChangeNotifierLinux>(
       std::unordered_set<std::string>());
