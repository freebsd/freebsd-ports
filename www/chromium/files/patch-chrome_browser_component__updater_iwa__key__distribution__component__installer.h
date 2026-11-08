--- chrome/browser/component_updater/iwa_key_distribution_component_installer.h.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/component_updater/iwa_key_distribution_component_installer.h
@@ -11,7 +11,7 @@
 
 namespace component_updater {
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIwaKeyDistributionComponent);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
