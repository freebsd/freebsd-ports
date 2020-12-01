--- chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher.cc.orig	2020-11-13 06:36:36 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher.cc
@@ -10,7 +10,7 @@
 #include "chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_mac.h"
 #elif defined(OS_WIN)
 #include "chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_win.h"
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_linux.h"
 #endif
 
@@ -58,7 +58,7 @@ std::unique_ptr<DeviceInfoFetcher> DeviceInfoFetcher::
   return std::make_unique<DeviceInfoFetcherMac>();
 #elif defined(OS_WIN)
   return std::make_unique<DeviceInfoFetcherWin>();
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return std::make_unique<DeviceInfoFetcherLinux>();
 #else
   return std::make_unique<StubDeviceFetcher>();
