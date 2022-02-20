--- chrome/browser/enterprise/signals/device_info_fetcher.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/enterprise/signals/device_info_fetcher.cc
@@ -10,7 +10,7 @@
 #include "chrome/browser/enterprise/signals/device_info_fetcher_mac.h"
 #elif defined(OS_WIN)
 #include "chrome/browser/enterprise/signals/device_info_fetcher_win.h"
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "chrome/browser/enterprise/signals/device_info_fetcher_linux.h"
 #endif
 
@@ -70,7 +70,7 @@ std::unique_ptr<DeviceInfoFetcher> DeviceInfoFetcher::
   return std::make_unique<DeviceInfoFetcherMac>();
 #elif defined(OS_WIN)
   return std::make_unique<DeviceInfoFetcherWin>();
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return std::make_unique<DeviceInfoFetcherLinux>();
 #else
   return std::make_unique<StubDeviceFetcher>();
