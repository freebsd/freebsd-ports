--- chrome/browser/chrome_content_browser_client.cc.orig	2018-02-24 16:25:09.000000000 +0100
+++ chrome/browser/chrome_content_browser_client.cc	2018-03-03 20:34:31.799512000 +0100
@@ -281,7 +281,7 @@
 #include "chromeos/chromeos_switches.h"
 #include "components/user_manager/user_manager.h"
 #include "services/service_manager/public/interfaces/interface_provider_spec.mojom.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #elif defined(OS_ANDROID)
 #include "base/android/application_status_listener.h"
@@ -316,7 +316,7 @@
 #include "chrome/common/importer/profile_import.mojom.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/browser/webshare/share_service_impl.h"
 #endif
 
@@ -330,7 +330,7 @@
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views_linux.h"
 #endif
 
@@ -912,7 +912,7 @@
   main_parts = new ChromeBrowserMainPartsMac(parameters);
 #elif defined(OS_CHROMEOS)
   main_parts = new chromeos::ChromeBrowserMainPartsChromeos(parameters);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   main_parts = new ChromeBrowserMainPartsLinux(parameters);
 #elif defined(OS_ANDROID)
   main_parts = new ChromeBrowserMainPartsAndroid(parameters);
@@ -928,7 +928,7 @@
   // Construct additional browser parts. Stages are called in the order in
   // which they are added.
 #if defined(TOOLKIT_VIEWS)
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViewsLinux());
 #else
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViews());
@@ -1651,7 +1651,7 @@
     command_line->AppendSwitchASCII(switches::kMetricsClientID,
                                     client_info->client_id);
   }
-#elif defined(OS_POSIX)
+#elif defined(OS_POSIX) && !defined(OS_BSD)
   bool enable_crash_reporter = breakpad::IsCrashReporterEnabled();
 #if defined(OS_CHROMEOS)
   // Chrome OS uses the OS-level crash_reporter for mash services, so disable
@@ -2913,7 +2913,7 @@
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -2949,7 +2949,7 @@
   }
 #endif  // defined(OS_ANDROID)
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #if defined(OS_WIN)
 base::string16 ChromeContentBrowserClient::GetAppContainerSidForSandboxType(
@@ -3630,7 +3630,7 @@
 #if defined(OS_ANDROID)
   frame_interfaces_parameterized_->AddInterface(base::Bind(
       &ForwardToJavaWebContentsRegistry<blink::mojom::ShareService>));
-#elif defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   frame_interfaces_->AddInterface(base::Bind(&ShareServiceImpl::Create));
 #endif
 
