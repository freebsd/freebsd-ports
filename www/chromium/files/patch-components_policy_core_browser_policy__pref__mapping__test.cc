--- components/policy/core/browser/policy_pref_mapping_test.cc.orig	2026-10-18 13:29:39 UTC
+++ components/policy/core/browser/policy_pref_mapping_test.cc
@@ -458,7 +458,7 @@ class PolicyTestCase {
     const std::string os("chromeos");
 #elif BUILDFLAG(IS_IOS)
     const std::string os("ios");
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     const std::string os("linux");
 #elif BUILDFLAG(IS_MAC)
     const std::string os("mac");
