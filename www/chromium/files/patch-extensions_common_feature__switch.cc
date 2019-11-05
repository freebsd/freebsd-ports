--- extensions/common/feature_switch.cc.orig	2019-10-21 19:06:34 UTC
+++ extensions/common/feature_switch.cc
@@ -42,11 +42,11 @@ class CommonSwitches {
                          FeatureSwitch::DEFAULT_ENABLED),
         load_media_router_component_extension(
             kLoadMediaRouterComponentExtensionFlag,
-#if BUILDFLAG(GOOGLE_CHROME_BRANDING)
+#if BUILDFLAG(GOOGLE_CHROME_BRANDING) || defined(OS_BSD)
             FeatureSwitch::DEFAULT_ENABLED)
 #else
             FeatureSwitch::DEFAULT_DISABLED)
-#endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
+#endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING) || defined(OS_BSD)
   {
   }
 
