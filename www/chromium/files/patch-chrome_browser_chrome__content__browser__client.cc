--- chrome/browser/chrome_content_browser_client.cc.orig	2017-04-19 19:06:29 UTC
+++ chrome/browser/chrome_content_browser_client.cc
@@ -244,7 +244,7 @@
 #include "mash/public/interfaces/launchable.mojom.h"
 #include "services/service_manager/public/cpp/interface_factory.h"
 #include "services/service_manager/public/interfaces/interface_provider_spec.mojom.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #elif defined(OS_ANDROID)
 #include "chrome/browser/android/app_hooks.h"
@@ -265,7 +265,7 @@
 #include "chrome/browser/webshare/share_service_impl.h"
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "base/debug/leak_annotations.h"
 #include "components/crash/content/app/breakpad_linux.h"
 #include "components/crash/content/browser/crash_handler_host_linux.h"
@@ -289,7 +289,7 @@
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views_linux.h"
 #endif
 
@@ -700,7 +700,7 @@ bool CertMatchesFilter(const net::X509Ce
   return false;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 breakpad::CrashHandlerHostLinux* CreateCrashHandlerHost(
     const std::string& process_type) {
   base::FilePath dumps_path;
@@ -1023,7 +1023,7 @@ content::BrowserMainParts* ChromeContent
   main_parts = new ChromeBrowserMainPartsMac(parameters);
 #elif defined(OS_CHROMEOS)
   main_parts = new chromeos::ChromeBrowserMainPartsChromeos(parameters);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   main_parts = new ChromeBrowserMainPartsLinux(parameters);
 #elif defined(OS_ANDROID)
   main_parts = new ChromeBrowserMainPartsAndroid(parameters);
@@ -1039,7 +1039,7 @@ content::BrowserMainParts* ChromeContent
   // Construct additional browser parts. Stages are called in the order in
   // which they are added.
 #if defined(TOOLKIT_VIEWS)
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViewsLinux());
 #else
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViews());
@@ -1680,7 +1680,7 @@ void ChromeContentBrowserClient::AppendE
     command_line->AppendSwitchASCII(switches::kMetricsClientID,
                                     client_info->client_id);
   }
-#elif defined(OS_POSIX)
+#elif defined(OS_POSIX) && !defined(OS_BSD)
   if (breakpad::IsCrashReporterEnabled()) {
     std::string switch_value;
     std::unique_ptr<metrics::ClientInfo> client_info =
@@ -2972,7 +2972,7 @@ void ChromeContentBrowserClient::GetAddi
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -3001,7 +3001,7 @@ void ChromeContentBrowserClient::GetAddi
   }
 #endif  // defined(OS_ANDROID)
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #if defined(OS_WIN)
 base::string16 ChromeContentBrowserClient::GetAppContainerSidForSandboxType(
@@ -3193,6 +3193,8 @@ void ChromeContentBrowserClient::Registe
         base::Bind(&ForwardShareServiceRequest,
                    web_contents->GetJavaInterfaces()->GetWeakPtr()));
   }
+#elif defined(OS_BSD)
+  NOTREACHED();
 #else
   if (AreExperimentalWebPlatformFeaturesEnabled() &&
       base::FeatureList::IsEnabled(features::kWebPayments)) {
