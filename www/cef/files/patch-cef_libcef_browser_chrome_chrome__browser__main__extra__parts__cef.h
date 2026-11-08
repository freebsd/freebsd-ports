--- cef/libcef/browser/chrome/chrome_browser_main_extra_parts_cef.h.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/browser/chrome/chrome_browser_main_extra_parts_cef.h
@@ -12,7 +12,7 @@
 #include "cef/libcef/browser/request_context_impl.h"
 #include "chrome/browser/chrome_browser_main_extra_parts.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/printing_context_linux.h"
 
 class CefPrintingContextLinuxDelegate;
@@ -61,7 +61,7 @@ class ChromeBrowserMainExtraPartsCef : p
   scoped_refptr<base::SingleThreadTaskRunner> user_visible_task_runner_;
   scoped_refptr<base::SingleThreadTaskRunner> user_blocking_task_runner_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Owns the printing delegate and print dialog factory registered in
   // ToolkitInitialized(). |printing_delegate_| is declared first so it is
   // destroyed after |print_dialog_factory_|; the destructor clears the global
