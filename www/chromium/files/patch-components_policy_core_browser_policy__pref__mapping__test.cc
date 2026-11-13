--- components/policy/core/browser/policy_pref_mapping_test.cc.orig	2026-11-11 14:44:17 UTC
+++ components/policy/core/browser/policy_pref_mapping_test.cc
@@ -461,7 +461,7 @@ class PolicyTestCase {
     static constexpr std::string_view kOsList[] = {"chromeos"};
 #elif BUILDFLAG(IS_IOS)
     static constexpr std::string_view kOsList[] = {"ios"};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     static constexpr std::string_view kOsList[] = {"linux"};
 #elif BUILDFLAG(IS_MAC)
     static constexpr std::string_view kOsList[] = {"mac"};
