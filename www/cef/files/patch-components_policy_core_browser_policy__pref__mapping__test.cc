--- components/policy/core/browser/policy_pref_mapping_test.cc.orig	2026-07-01 06:24:19 UTC
+++ components/policy/core/browser/policy_pref_mapping_test.cc
@@ -434,7 +434,7 @@ class PolicyTestCase {
     const std::string os("chromeos");
 #elif BUILDFLAG(IS_IOS)
     const std::string os("ios");
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     const std::string os("linux");
 #elif BUILDFLAG(IS_MAC)
     const std::string os("mac");
