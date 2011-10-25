--- chrome/browser/chrome_content_browser_client.cc.orig	2011-10-07 08:32:35.000000000 +0000
+++ chrome/browser/chrome_content_browser_client.cc	2011-10-10 20:09:07.754749149 +0000
@@ -71,7 +71,7 @@
 #include "net/base/cookie_options.h"
 #include "ui/base/resource/resource_bundle.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "base/linux_util.h"
 #include "chrome/browser/browser_main_gtk.h"
 #include "chrome/browser/crash_handler_host_linux.h"
@@ -81,7 +81,7 @@
 #include "chrome/browser/ui/views/tab_contents/tab_contents_view_touch.h"
 #elif defined(TOOLKIT_VIEWS)
 #include "chrome/browser/ui/views/tab_contents/tab_contents_view_views.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "chrome/browser/tab_contents/tab_contents_view_gtk.h"
 #elif defined(OS_MACOSX)
 #include "chrome/browser/tab_contents/tab_contents_view_mac.h"
@@ -129,7 +129,7 @@
   return new BrowserMainPartsMac(parameters);
 #elif defined(OS_CHROMEOS)
   return new BrowserMainPartsChromeos(parameters);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   return new BrowserMainPartsGtk(parameters);
 #else
   return NULL;
@@ -142,7 +142,7 @@
   return new TabContentsViewTouch(tab_contents);
 #elif defined(TOOLKIT_VIEWS)
   return new TabContentsViewViews(tab_contents);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   return new TabContentsViewGtk(tab_contents);
 #elif defined(OS_MACOSX)
   return tab_contents_view_mac::CreateTabContentsView(tab_contents);
@@ -771,7 +771,7 @@
   return g_browser_process->system_request_context();
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 int ChromeContentBrowserClient::GetCrashSignalFD(
     const std::string& process_type) {
   if (process_type == switches::kRendererProcess)
@@ -794,7 +794,7 @@
 
   return -1;
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD)
 
 #if defined(OS_WIN)
 const wchar_t* ChromeContentBrowserClient::GetResourceDllName() {
