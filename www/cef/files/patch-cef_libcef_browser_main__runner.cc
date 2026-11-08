--- cef/libcef/browser/main_runner.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/browser/main_runner.cc
@@ -13,7 +13,9 @@
 #include "base/synchronization/waitable_event.h"
 #include "cef/libcef/browser/browser_message_loop.h"
 #include "cef/libcef/browser/chrome/chrome_content_browser_client_cef.h"
+#if !BUILDFLAG(IS_BSD)
 #include "cef/libcef/browser/crashpad_runner.h"
+#endif
 #include "cef/libcef/browser/thread_util.h"
 #include "cef/libcef/common/app_manager.h"
 #include "cef/libcef/common/cef_switches.h"
@@ -194,9 +196,11 @@ int CefMainRunner::RunAsHelperProcess(co
     return CEF_RESULT_CODE_BAD_PROCESS_TYPE;
   }
 
+#if !BUILDFLAG(IS_BSD)
   if (process_type == crash_reporter::switches::kCrashpadHandler) {
     return crashpad_runner::RunAsCrashpadHandler(command_line);
   }
+#endif
 
   auto main_delegate = std::make_unique<ChromeMainDelegateCef>(
       /*runner=*/nullptr, /*settings=*/nullptr, application);
