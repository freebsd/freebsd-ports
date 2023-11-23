--- src/3rdparty/chromium/chrome/browser/media/webrtc/chrome_screen_enumerator.cc.orig	2023-03-09 06:31:50 UTC
+++ src/3rdparty/chromium/chrome/browser/media/webrtc/chrome_screen_enumerator.cc
@@ -20,7 +20,7 @@
 #if BUILDFLAG(IS_CHROMEOS_ASH)
 #include "ash/shell.h"
 #include "ui/aura/window.h"
-#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/functional/callback.h"
 #include "content/public/browser/desktop_capture.h"
 #endif
@@ -31,7 +31,7 @@ base::LazyInstance<std::vector<aura::Window*>>::Destru
     root_windows_for_testing_ = LAZY_INSTANCE_INITIALIZER;
 }  // namespace
 
-#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace {
 base::LazyInstance<std::unique_ptr<webrtc::DesktopCapturer>>::DestructorAtExit
     g_desktop_capturer_for_testing = LAZY_INSTANCE_INITIALIZER;
@@ -77,7 +77,7 @@ blink::mojom::StreamDevicesSetPtr EnumerateScreens(
   return stream_devices_set;
 }
 
-#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 blink::mojom::StreamDevicesSetPtr EnumerateScreens(
     blink::mojom::MediaStreamType stream_type) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
@@ -128,7 +128,7 @@ void ChromeScreenEnumerator::SetRootWindowsForTesting(
   root_windows_for_testing_.Get() = std::move(root_windows);
 }
 
-#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromeScreenEnumerator::SetDesktopCapturerForTesting(
     std::unique_ptr<webrtc::DesktopCapturer> capturer) {
   g_desktop_capturer_for_testing.Get() = std::move(capturer);
@@ -144,7 +144,7 @@ void ChromeScreenEnumerator::EnumerateScreens(
   DCHECK(base::FeatureList::IsEnabled(
       features::kGetDisplayMediaSetAutoSelectAllScreens));
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   content::GetUIThreadTaskRunner({})->PostTaskAndReplyWithResult(
       FROM_HERE, base::BindOnce(::EnumerateScreens, stream_type),
       base::BindOnce(
