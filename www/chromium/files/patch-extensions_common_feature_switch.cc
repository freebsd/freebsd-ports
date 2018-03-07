--- extensions/common/feature_switch.cc.orig	2018-02-24 16:25:15.000000000 +0100
+++ extensions/common/feature_switch.cc	2018-03-04 02:30:07.857694000 +0100
@@ -50,11 +50,7 @@
                          FeatureSwitch::DEFAULT_ENABLED),
         load_media_router_component_extension(
             kLoadMediaRouterComponentExtensionFlag,
-#if defined(GOOGLE_CHROME_BUILD)
             FeatureSwitch::DEFAULT_ENABLED),
-#else
-            FeatureSwitch::DEFAULT_DISABLED),
-#endif  // defined(GOOGLE_CHROME_BUILD)
         yield_between_content_script_runs(
             switches::kYieldBetweenContentScriptRuns,
             kYieldBetweenContentScriptRunsFieldTrial,
