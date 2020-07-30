--- chrome/common/channel_info_posix.cc.orig	2020-07-07 21:57:33 UTC
+++ chrome/common/channel_info_posix.cc
@@ -67,7 +67,7 @@ std::string GetChannelSuffixForDataDir() {
   }
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 std::string GetDesktopName(base::Environment* env) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   // Google Chrome packaged as a snap is a special case: the application name
@@ -96,7 +96,7 @@ std::string GetDesktopName(base::Environment* env) {
   return "chromium-browser.desktop";
 #endif
 }
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
 version_info::Channel GetChannel() {
   return GetChannelImpl(nullptr);
