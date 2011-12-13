--- chrome/browser/chrome_content_browser_client.cc.orig	2011-11-01 10:43:20.000000000 +0200
+++ chrome/browser/chrome_content_browser_client.cc	2011-11-19 19:22:29.000000000 +0200
@@ -81,18 +81,18 @@
 #include "chrome/browser/chrome_browser_main_win.h"
 #elif defined(OS_MACOSX)
 #include "chrome/browser/chrome_browser_main_mac.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "chrome/browser/chrome_browser_main_gtk.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "base/linux_util.h"
 #include "chrome/browser/crash_handler_host_linux.h"
 #endif
 
 #if defined(TOOLKIT_VIEWS)
 #include "chrome/browser/ui/views/tab_contents/tab_contents_view_views.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "chrome/browser/tab_contents/tab_contents_view_gtk.h"
 #elif defined(OS_MACOSX)
 #include "chrome/browser/tab_contents/tab_contents_view_mac.h"
@@ -108,7 +108,7 @@
 #elif defined(OS_WIN)
 #include "chrome/browser/renderer_host/render_widget_host_view_views.h"
 #include "content/browser/renderer_host/render_widget_host_view_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "content/browser/renderer_host/render_widget_host_view_gtk.h"
 #elif defined(OS_MACOSX)
 #include "content/browser/renderer_host/render_widget_host_view_mac.h"
@@ -195,7 +195,7 @@
   return new ChromeBrowserMainPartsWin(parameters);
 #elif defined(OS_MACOSX)
   return new ChromeBrowserMainPartsMac(parameters);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   return new ChromeBrowserMainPartsGtk(parameters);
 #else
   return NULL;
@@ -210,7 +210,7 @@
   if (views::Widget::IsPureViews())
     return new RenderWidgetHostViewViews(widget);
   return new RenderWidgetHostViewWin(widget);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   return new RenderWidgetHostViewGtk(widget);
 #elif defined(OS_MACOSX)
   return render_widget_host_view_mac::CreateRenderWidgetHostView(widget);
@@ -223,7 +223,7 @@
     TabContents* tab_contents) {
 #if defined(TOOLKIT_VIEWS)
   return new TabContentsViewViews(tab_contents);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   return new TabContentsViewGtk(tab_contents);
 #elif defined(OS_MACOSX)
   return tab_contents_view_mac::CreateTabContentsView(tab_contents);
@@ -911,7 +911,7 @@
   return download_util::GetDefaultDownloadDirectory();
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 int ChromeContentBrowserClient::GetCrashSignalFD(
     const CommandLine& command_line) {
   if (command_line.HasSwitch(switches::kExtensionProcess)) {
@@ -937,7 +937,7 @@
 
   return -1;
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD)
 
 #if defined(OS_WIN)
 const wchar_t* ChromeContentBrowserClient::GetResourceDllName() {
