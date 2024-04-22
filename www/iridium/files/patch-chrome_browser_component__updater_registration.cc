--- chrome/browser/component_updater/registration.cc.orig	2024-02-04 14:46:08 UTC
+++ chrome/browser/component_updater/registration.cc
@@ -223,7 +223,7 @@ void RegisterComponentsForUpdate() {
 
   RegisterTpcdMetadataComponent(cus);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/1490685): Remove this test component once the
   // experiment has concluded.
   if (base::FeatureList::IsEnabled(features::kPayloadTestComponent)) {
