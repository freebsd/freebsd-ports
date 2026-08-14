--- components/policy/core/browser/policy_pref_mapping_test.cc.orig	2026-08-13 16:48:13 UTC
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
