--- chrome/browser/component_updater/iwa_key_distribution_component_installer.cc.orig	2025-05-05 10:57:53 UTC
+++ chrome/browser/component_updater/iwa_key_distribution_component_installer.cc
@@ -64,7 +64,7 @@ component_updater::OnDemandUpdater::Priority GetOnDema
 
 namespace component_updater {
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kIwaKeyDistributionComponent,
              "IwaKeyDistributionComponent",
 #if BUILDFLAG(IS_CHROMEOS)
@@ -89,7 +89,7 @@ bool IwaKeyDistributionComponentInstallerPolicy::IsSup
   // the main IWA feature.
 #if BUILDFLAG(IS_WIN)
   return base::FeatureList::IsEnabled(features::kIsolatedWebApps);
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(kIwaKeyDistributionComponent);
 #else
   return false;
