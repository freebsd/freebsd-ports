--- chrome/common/channel_info.h.orig	2021-04-14 18:40:56 UTC
+++ chrome/common/channel_info.h
@@ -70,7 +70,7 @@ std::string GetChannelSuffixForDataDir();
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 // Returns the channel-specific filename of the desktop shortcut used to launch
 // the browser.
 std::string GetDesktopName(base::Environment* env);
