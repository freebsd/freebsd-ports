--- chrome/browser/policy/developer_tools_policy_checker_factory.cc.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/policy/developer_tools_policy_checker_factory.cc
@@ -58,7 +58,7 @@ void DeveloperToolsPolicyCheckerFactory::RegisterProfi
       static_cast<int>(DeveloperToolsPolicyHandler::Availability::
                            kDisallowedForForceInstalledExtensions));
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   registry->RegisterListPref(prefs::kDeveloperToolsAvailabilityAllowlist);
   registry->RegisterListPref(prefs::kDeveloperToolsAvailabilityBlocklist);
 #endif
