--- chrome/browser/media/webrtc/chrome_screen_enumerator.h.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/media/webrtc/chrome_screen_enumerator.h
@@ -18,7 +18,7 @@
 namespace aura {
 class Window;
 }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace webrtc {
 class DesktopCapturer;
 }
@@ -39,7 +39,7 @@ class ChromeScreenEnumerator : public media::ScreenEnu
 #if BUILDFLAG(IS_CHROMEOS)
   static void SetRootWindowsForTesting(
       std::vector<raw_ptr<aura::Window, VectorExperimental>> root_windows);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static void SetDesktopCapturerForTesting(
       std::unique_ptr<webrtc::DesktopCapturer> capturer);
 #endif
