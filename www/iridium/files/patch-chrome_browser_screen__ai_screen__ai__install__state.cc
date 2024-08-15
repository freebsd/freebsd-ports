--- chrome/browser/screen_ai/screen_ai_install_state.cc.orig	2024-08-01 05:47:53 UTC
+++ chrome/browser/screen_ai/screen_ai_install_state.cc
@@ -17,7 +17,7 @@
 #include "services/screen_ai/public/cpp/utilities.h"
 #include "ui/accessibility/accessibility_features.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/cpu.h"
 #include "base/files/file_util.h"
 #endif
@@ -27,7 +27,7 @@ const int kScreenAICleanUpDelayInDays = 30;
 const char kMinExpectedVersion[] = "124.2";
 
 bool IsDeviceCompatible() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if defined(ARCH_CPU_X86_FAMILY)
   // Check if the CPU has the required instruction set to run the Screen AI
   // library.
