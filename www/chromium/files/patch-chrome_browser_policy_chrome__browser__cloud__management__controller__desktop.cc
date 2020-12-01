--- chrome/browser/policy/chrome_browser_cloud_management_controller_desktop.cc.orig	2020-11-16 14:21:44 UTC
+++ chrome/browser/policy/chrome_browser_cloud_management_controller_desktop.cc
@@ -43,9 +43,9 @@
 #include "chrome/browser/policy/browser_dm_token_storage_mac.h"
 #endif  // defined(OS_MAC)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "chrome/browser/policy/browser_dm_token_storage_linux.h"
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 #include "chrome/browser/policy/browser_dm_token_storage_win.h"
@@ -176,7 +176,7 @@ void ChromeBrowserCloudManagementControllerDesktop::
 
 #if defined(OS_MAC)
   storage_delegate = std::make_unique<BrowserDMTokenStorageMac>();
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   storage_delegate = std::make_unique<BrowserDMTokenStorageLinux>();
 #elif defined(OS_WIN)
   storage_delegate = std::make_unique<BrowserDMTokenStorageWin>();
