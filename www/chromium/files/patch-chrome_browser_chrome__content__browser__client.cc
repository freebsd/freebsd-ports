--- chrome/browser/chrome_content_browser_client.cc.orig	2017-06-15 21:03:01.000000000 +0200
+++ chrome/browser/chrome_content_browser_client.cc	2017-06-18 04:59:41.793684000 +0200
@@ -249,7 +249,7 @@
 #include "mash/public/interfaces/launchable.mojom.h"
 #include "services/service_manager/public/cpp/interface_factory.h"
 #include "services/service_manager/public/interfaces/interface_provider_spec.mojom.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #elif defined(OS_ANDROID)
 #include "chrome/browser/android/app_hooks.h"
@@ -266,7 +266,7 @@
 #include "chrome/browser/payments/payment_request_factory.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/browser/webshare/share_service_impl.h"
 #endif
 
@@ -294,7 +294,7 @@
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views_linux.h"
 #endif
 
@@ -711,7 +711,7 @@
   return false;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 breakpad::CrashHandlerHostLinux* CreateCrashHandlerHost(
     const std::string& process_type) {
   base::FilePath dumps_path;
@@ -761,7 +761,7 @@
 
   return -1;
 }
-#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 void SetApplicationLocaleOnIOThread(const std::string& locale) {
   DCHECK_CURRENTLY_ON(BrowserThread::IO);
@@ -1038,7 +1038,7 @@
   main_parts = new ChromeBrowserMainPartsMac(parameters);
 #elif defined(OS_CHROMEOS)
   main_parts = new chromeos::ChromeBrowserMainPartsChromeos(parameters);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   main_parts = new ChromeBrowserMainPartsLinux(parameters);
 #elif defined(OS_ANDROID)
   main_parts = new ChromeBrowserMainPartsAndroid(parameters);
@@ -1054,7 +1054,7 @@
   // Construct additional browser parts. Stages are called in the order in
   // which they are added.
 #if defined(TOOLKIT_VIEWS)
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViewsLinux());
 #else
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViews());
@@ -1704,7 +1704,7 @@
     command_line->AppendSwitchASCII(switches::kMetricsClientID,
                                     client_info->client_id);
   }
-#elif defined(OS_POSIX)
+#elif defined(OS_POSIX) && !defined(OS_BSD)
   if (breakpad::IsCrashReporterEnabled()) {
     std::string switch_value;
     std::unique_ptr<metrics::ClientInfo> client_info =
@@ -2982,7 +2982,7 @@
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -3011,7 +3011,7 @@
   }
 #endif  // defined(OS_ANDROID)
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #if defined(OS_WIN)
 base::string16 ChromeContentBrowserClient::GetAppContainerSidForSandboxType(
@@ -3219,7 +3219,7 @@
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   if (!ChromeOriginTrialPolicy().IsFeatureDisabled("WebShare")) {
     registry->AddInterface(base::Bind(&ShareServiceImpl::Create));
   }
