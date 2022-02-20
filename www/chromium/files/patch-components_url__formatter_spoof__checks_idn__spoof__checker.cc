--- components/url_formatter/spoof_checks/idn_spoof_checker.cc.orig	2022-02-07 13:39:41 UTC
+++ components/url_formatter/spoof_checks/idn_spoof_checker.cc
@@ -285,7 +285,7 @@ IDNSpoofChecker::IDNSpoofChecker() {
   // The ideal fix would be to change the omnibox font used for Thai. In
   // that case, the Linux-only list should be revisited and potentially
   // removed.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
        "[ทนบพรหเแ๐ดลปฟม]",
 #else
        "[บพเแ๐]",
