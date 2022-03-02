--- chrome/updater/device_management/dm_client.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/updater/device_management/dm_client.cc
@@ -36,7 +36,7 @@
 #include "chrome/updater/win/net/network.h"
 #elif BUILDFLAG(IS_MAC)
 #include "chrome/updater/mac/net/network.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/updater/linux/net/network.h"
 #endif
 
