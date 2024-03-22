--- chrome/browser/screen_ai/screen_ai_install_state.cc.orig	2024-03-22 08:19:40 UTC
+++ chrome/browser/screen_ai/screen_ai_install_state.cc
@@ -24,7 +24,7 @@
 #include "content/public/browser/browser_thread.h"
 #include "ui/accessibility/accessibility_features.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/cpu.h"
 #include "base/files/file_util.h"
 #endif
@@ -36,7 +36,7 @@ const char kMinExpectedVersion[] = "123.1";
 bool IsDeviceCompatible() {
   // Check if the CPU has the required instruction set to run the Screen AI
   // library.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!base::CPU().has_sse41()) {
     return false;
   }
