--- chrome/browser/component_updater/iwa_key_distribution_component_installer.h.orig	2026-01-14 08:33:23 UTC
+++ chrome/browser/component_updater/iwa_key_distribution_component_installer.h
@@ -26,7 +26,7 @@ class IwaKeyDistributionInfoProvider;
 
 namespace component_updater {
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIwaKeyDistributionComponent);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
