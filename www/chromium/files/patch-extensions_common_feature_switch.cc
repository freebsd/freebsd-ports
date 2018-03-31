--- extensions/common/feature_switch.cc.orig	2018-03-20 23:05:25.000000000 +0100
+++ extensions/common/feature_switch.cc	2018-03-24 17:46:50.886191000 +0100
@@ -46,11 +46,7 @@
                          FeatureSwitch::DEFAULT_ENABLED),
         load_media_router_component_extension(
             kLoadMediaRouterComponentExtensionFlag,
-#if defined(GOOGLE_CHROME_BUILD)
             FeatureSwitch::DEFAULT_ENABLED)
-#else
-            FeatureSwitch::DEFAULT_DISABLED)
-#endif  // defined(GOOGLE_CHROME_BUILD)
   {
   }
 
