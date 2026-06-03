--- chrome/common/channel_info_posix.cc.orig	2026-01-14 08:33:23 UTC
+++ chrome/common/channel_info_posix.cc
@@ -92,7 +92,7 @@ std::string GetChannelSuffixForDataDir() {
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string GetChannelSuffixForExtraFlagsEnvVarName() {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   const auto channel_state = GetChannelImpl();
@@ -117,7 +117,7 @@ std::string GetChannelSuffixForExtraFlagsEnvVarName() 
 }
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string GetDesktopName(base::Environment* env) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   // Google Chrome packaged as a snap is a special case: the application name
