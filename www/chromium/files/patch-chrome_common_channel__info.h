--- chrome/common/channel_info.h.orig	2020-05-13 18:39:39 UTC
+++ chrome/common/channel_info.h
@@ -61,7 +61,7 @@ bool IsSideBySideCapable();
 std::string GetChannelSuffixForDataDir();
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Returns the channel-specific filename of the desktop shortcut used to launch
 // the browser.
 std::string GetDesktopName(base::Environment* env);
