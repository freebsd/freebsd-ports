--- net/base/network_change_notifier.cc.orig	2020-03-03 18:53:10 UTC
+++ net/base/network_change_notifier.cc
@@ -35,7 +35,7 @@
 #include "net/base/network_change_notifier_linux.h"
 #elif defined(OS_MACOSX)
 #include "net/base/network_change_notifier_mac.h"
-#elif defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#elif defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "net/base/network_change_notifier_posix.h"
 #elif defined(OS_FUCHSIA)
 #include "net/base/network_change_notifier_fuchsia.h"
@@ -229,7 +229,7 @@ std::unique_ptr<NetworkChangeNotifier> NetworkChangeNo
   // service in a separate process.
   return std::make_unique<NetworkChangeNotifierPosix>(initial_type,
                                                       initial_subtype);
-#elif defined(OS_CHROMEOS)
+#elif defined(OS_CHROMEOS) || defined(OS_BSD)
   return std::make_unique<NetworkChangeNotifierPosix>(initial_type,
                                                       initial_subtype);
 #elif defined(OS_LINUX)
@@ -241,7 +241,6 @@ std::unique_ptr<NetworkChangeNotifier> NetworkChangeNo
   return std::make_unique<NetworkChangeNotifierFuchsia>(
       0 /* required_features */);
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
