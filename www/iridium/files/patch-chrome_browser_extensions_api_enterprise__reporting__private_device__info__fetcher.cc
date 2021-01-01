--- chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher.cc.orig	2020-03-17 09:37:45 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher.cc
@@ -11,7 +11,7 @@
 #include "chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_mac.h"
 #elif defined(OS_WIN)
 #include "chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_linux.h"
 #endif
 
@@ -58,7 +58,7 @@ std::unique_ptr<DeviceInfoFetcher> DeviceInfoFetcher::
   return std::make_unique<DeviceInfoFetcherMac>();
 #elif defined(OS_WIN)
   return std::make_unique<DeviceInfoFetcherWin>();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return std::make_unique<DeviceInfoFetcherLinux>();
 #else
   return std::make_unique<StubDeviceFetcher>();
