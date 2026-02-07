--- src/3rdparty/chromium/components/policy/core/browser/policy_pref_mapping_test.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/policy/core/browser/policy_pref_mapping_test.cc
@@ -408,7 +408,7 @@ class PolicyTestCase {
     const std::string os("chromeos_ash");
 #elif BUILDFLAG(IS_IOS)
     const std::string os("ios");
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     const std::string os("linux");
 #elif BUILDFLAG(IS_MAC)
     const std::string os("mac");
