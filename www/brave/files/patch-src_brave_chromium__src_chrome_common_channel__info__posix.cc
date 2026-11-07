--- src/brave/chromium_src/chrome/common/channel_info_posix.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/chrome/common/channel_info_posix.cc
@@ -27,7 +27,7 @@
   return std::string();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 std::string GetChannelSuffixForExtraFlagsEnvVarName() {
 #if defined(OFFICIAL_BUILD)
   version_info::Channel product_channel(chrome::GetChannel());
@@ -51,9 +51,9 @@
              : std::string();
 #endif  // defined(OFFICIAL_BUILD)
 }
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 
-#if BUILDFLAG(IS_LINUX)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 std::string GetDesktopName(base::Environment* env) {
   if (auto brave_snap = env->GetVar("BRAVE_SNAP");
       brave_snap && *brave_snap == "1") {
@@ -95,7 +95,7 @@
   return "brave-browser.desktop";
 #endif
 }
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 
 version_info::Channel GetChannel() {
   return brave::GetChannelImpl(nullptr, nullptr);
