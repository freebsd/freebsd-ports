--- chrome/updater/device_management/dm_client.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/updater/device_management/dm_client.cc
@@ -36,7 +36,7 @@
 #include "chrome/updater/win/net/network.h"
 #elif defined(OS_MAC)
 #include "chrome/updater/mac/net/network.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/updater/linux/net/network.h"
 #endif
 
