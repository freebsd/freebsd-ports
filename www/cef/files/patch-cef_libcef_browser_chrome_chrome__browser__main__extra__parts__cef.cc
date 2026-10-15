--- cef/libcef/browser/chrome/chrome_browser_main_extra_parts_cef.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/browser/chrome/chrome_browser_main_extra_parts_cef.cc
@@ -16,7 +16,7 @@
 #include "chrome/browser/ui/views/chrome_constrained_window_views_client.h"
 #include "components/constrained_window/constrained_window_views.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/linux_util.h"
 #include "cef/libcef/browser/printing/print_dialog_linux.h"
 #endif
@@ -28,7 +28,7 @@
 ChromeBrowserMainExtraPartsCef::ChromeBrowserMainExtraPartsCef() = default;
 
 ChromeBrowserMainExtraPartsCef::~ChromeBrowserMainExtraPartsCef() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Clear the global printing delegate pointer before |printing_delegate_| is
   // destroyed so it does not dangle. |print_dialog_factory_| unregisters itself
   // via the PrintDialogLinuxFactory destructor.
@@ -60,7 +60,7 @@ void ChromeBrowserMainExtraPartsCef::Pos
   // allows ProcessSingleton to begin processing messages.
   startup_browser_creator::RegisterProcessCommandLineCallback();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This may be called indirectly via StartupBrowserCreator::LaunchBrowser.
   // Call it here before blocking is disallowed to avoid assertions.
   base::GetLinuxDistro();
@@ -99,7 +99,7 @@ void ChromeBrowserMainExtraPartsCef::Too
   SetConstrainedWindowViewsClient(CreateAlloyConstrainedWindowViewsClient(
       CreateChromeConstrainedWindowViewsClient()));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   printing_delegate_ = std::make_unique<CefPrintingContextLinuxDelegate>();
   auto* default_delegate =
       ui::PrintingContextLinuxDelegate::SetInstance(printing_delegate_.get());
