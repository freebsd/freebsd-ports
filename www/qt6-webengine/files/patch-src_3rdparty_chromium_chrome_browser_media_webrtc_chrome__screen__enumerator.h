--- src/3rdparty/chromium/chrome/browser/media/webrtc/chrome_screen_enumerator.h.orig	2023-03-09 06:31:50 UTC
+++ src/3rdparty/chromium/chrome/browser/media/webrtc/chrome_screen_enumerator.h
@@ -21,7 +21,7 @@ namespace aura {
 class Window;
 }
 
-#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace webrtc {
 class DesktopCapturer;
 }
@@ -42,7 +42,7 @@ class ChromeScreenEnumerator : public media::ScreenEnu
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   static void SetRootWindowsForTesting(std::vector<aura::Window*> root_windows);
-#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static void SetDesktopCapturerForTesting(
       std::unique_ptr<webrtc::DesktopCapturer> capturer);
 #endif
