--- chrome/browser/screen_ai/screen_ai_install_state.cc.orig	2026-08-13 16:48:13 UTC
+++ chrome/browser/screen_ai/screen_ai_install_state.cc
@@ -28,7 +28,7 @@ bool IsDeviceCompatible() {
   // Check if the CPU has the required instruction set to run the Screen AI
   // library.
   static const bool device_compatible = base::CPU().has_sse42();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, the library is only built for X86 CPUs.
   static constexpr bool device_compatible = false;
 #else
