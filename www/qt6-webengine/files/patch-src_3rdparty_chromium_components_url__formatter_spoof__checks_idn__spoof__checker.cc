--- src/3rdparty/chromium/components/url_formatter/spoof_checks/idn_spoof_checker.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/components/url_formatter/spoof_checks/idn_spoof_checker.cc
@@ -292,7 +292,7 @@ IDNSpoofChecker::IDNSpoofChecker() {
   // The ideal fix would be to change the omnibox font used for Thai. In
   // that case, the Linux-only list should be revisited and potentially
   // removed.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
        "[ทนบพรหเแ๐ดลปฟม]",
 #else
        "[บพเแ๐]",
