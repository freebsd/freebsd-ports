--- chrome/common/channel_info_posix.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/common/channel_info_posix.cc
@@ -93,7 +93,7 @@ std::string GetChannelSuffixForDataDir() {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 std::string GetDesktopName(base::Environment* env) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   // Google Chrome packaged as a snap is a special case: the application name
