--- chrome/browser/chrome_content_browser_client.cc.orig	2017-03-09 20:04:28 UTC
+++ chrome/browser/chrome_content_browser_client.cc
@@ -242,7 +242,7 @@
 #include "chrome/browser/ui/browser_dialogs.h"
 #include "chromeos/chromeos_switches.h"
 #include "components/user_manager/user_manager.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #elif defined(OS_ANDROID)
 #include "chrome/browser/chrome_browser_main_android.h"
@@ -258,7 +258,7 @@
 #include "chrome/browser/payments/payment_request_factory.h"
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "base/debug/leak_annotations.h"
 #include "components/crash/content/app/breakpad_linux.h"
 #include "components/crash/content/browser/crash_handler_host_linux.h"
@@ -281,7 +281,7 @@
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views_linux.h"
 #endif
 
@@ -576,7 +576,7 @@ bool CertMatchesFilter(const net::X509Ce
   return false;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 breakpad::CrashHandlerHostLinux* CreateCrashHandlerHost(
     const std::string& process_type) {
   base::FilePath dumps_path;
@@ -899,7 +899,7 @@ content::BrowserMainParts* ChromeContent
   main_parts = new ChromeBrowserMainPartsMac(parameters);
 #elif defined(OS_CHROMEOS)
   main_parts = new chromeos::ChromeBrowserMainPartsChromeos(parameters);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   main_parts = new ChromeBrowserMainPartsLinux(parameters);
 #elif defined(OS_ANDROID)
   main_parts = new ChromeBrowserMainPartsAndroid(parameters);
@@ -915,7 +915,7 @@ content::BrowserMainParts* ChromeContent
   // Construct additional browser parts. Stages are called in the order in
   // which they are added.
 #if defined(TOOLKIT_VIEWS)
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViewsLinux());
 #else
   ChromeBrowserMainExtraPartsViews* extra_parts_views =
@@ -1552,7 +1552,7 @@ void ChromeContentBrowserClient::AppendE
     command_line->AppendSwitchASCII(switches::kMetricsClientID,
                                     client_info->client_id);
   }
-#elif defined(OS_POSIX)
+#elif defined(OS_POSIX) && !defined(OS_BSD)
   if (breakpad::IsCrashReporterEnabled()) {
     std::string switch_value;
     std::unique_ptr<metrics::ClientInfo> client_info =
@@ -2808,7 +2808,7 @@ void ChromeContentBrowserClient::GetAddi
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -2837,7 +2837,7 @@ void ChromeContentBrowserClient::GetAddi
   }
 #endif  // defined(OS_ANDROID)
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #if defined(OS_WIN)
 base::string16 ChromeContentBrowserClient::GetAppContainerSidForSandboxType(
