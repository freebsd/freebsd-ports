--- content/browser/browser_main_loop.cc.orig	2021-04-14 18:41:02 UTC
+++ content/browser/browser_main_loop.cc
@@ -368,7 +368,7 @@ std::unique_ptr<base::MemoryPressureMonitor> CreateMem
   if (chromeos::switches::MemoryPressureHandlingEnabled())
     monitor = std::make_unique<util::MultiSourceMemoryPressureMonitor>();
 #elif defined(OS_MAC) || defined(OS_WIN) || defined(OS_FUCHSIA) || \
-    ((defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) &&       \
+    defined(OS_BSD) || ((defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
      !BUILDFLAG(IS_CHROMECAST))
   monitor = std::make_unique<util::MultiSourceMemoryPressureMonitor>();
 #endif
@@ -562,7 +562,7 @@ int BrowserMainLoop::EarlyInitialization() {
 
   // Up the priority of the UI thread unless it was already high (since Mac
   // and recent versions of Android (O+) do this automatically).
-#if !defined(OS_MAC)
+#if !defined(OS_MAC) && !defined(OS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kBrowserUseDisplayThreadPriority) &&
       base::PlatformThread::GetCurrentThreadPriority() <
@@ -572,7 +572,7 @@ int BrowserMainLoop::EarlyInitialization() {
   }
 #endif  // !defined(OS_MAC)
 
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_ANDROID)
   // We use quite a few file descriptors for our IPC as well as disk the disk
   // cache,and the default limit on the Mac is low (256), so bump it up.
@@ -582,7 +582,7 @@ int BrowserMainLoop::EarlyInitialization() {
   // users can easily hit this limit with many open tabs. Bump up the limit to
   // an arbitrarily high number. See https://crbug.com/539567
   base::IncreaseFdLimitTo(8192);
-#endif  // defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) ||
+#endif  // defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) ||
         // defined(OS_ANDROID)
 
 #if defined(OS_WIN)
