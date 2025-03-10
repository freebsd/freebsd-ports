--- chrome/browser/ui/ui_features.cc.orig	2025-02-22 18:06:53 UTC
+++ chrome/browser/ui/ui_features.cc
@@ -90,7 +90,7 @@ bool IsExtensionMenuInRootAppMenu() {
   return base::FeatureList::IsEnabled(kExtensionsMenuInAppMenu);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables the feature to remove the last confirmation dialog when relaunching
 // to update Chrome.
 BASE_FEATURE(kFewerUpdateConfirmations,
@@ -264,7 +264,7 @@ BASE_FEATURE(kTabOrganizationAppMenuItem,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kMultiTabOrganization,
              "MultiTabOrganization",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -412,7 +412,7 @@ BASE_FEATURE(kViewsJSAppModalDialog,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUsePortalAccentColor,
              "UsePortalAccentColor",
              base::FEATURE_ENABLED_BY_DEFAULT);
