--- extensions/common/feature_switch.cc.orig	2018-01-21 13:37:32.991326000 +0100
+++ extensions/common/feature_switch.cc	2018-01-21 13:37:55.308701000 +0100
@@ -52,11 +52,7 @@
                          FeatureSwitch::DEFAULT_ENABLED),
         load_media_router_component_extension(
             kLoadMediaRouterComponentExtensionFlag,
-#if defined(GOOGLE_CHROME_BUILD)
             FeatureSwitch::DEFAULT_ENABLED),
-#else
-            FeatureSwitch::DEFAULT_DISABLED),
-#endif  // defined(GOOGLE_CHROME_BUILD)
         native_crx_bindings(switches::kNativeCrxBindings,
                             kNativeCrxBindingsFieldTrial,
                             FeatureSwitch::DEFAULT_DISABLED),
