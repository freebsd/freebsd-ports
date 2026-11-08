--- src/base/feature_list.cc.orig	2026-06-01 00:00:00 UTC
+++ src/base/feature_list.cc
@@ -726,9 +726,13 @@
 }
 
 bool FeatureList::IsFeatureOverridden(std::string_view feature_name) const {
+#if !defined(BRAVE_REDIRECT_CC_BUILD)
+  // Defined in the chromium_src override of base/feature_list.h, which is
+  // unavailable here.
   if (internal::IsCompileOverriddenFeature(feature_name)) {
     return true;
   }
+#endif
   return GetOverrideEntryByFeatureName(feature_name);
 }
 
@@ -1195,9 +1199,11 @@
 
   return std::nullopt;
   }();
+#if !defined(BRAVE_REDIRECT_CC_BUILD)
   if (!state.has_value() && internal::IsCompileOverriddenFeature(feature.name)) {
     return IsFeatureEnabled(feature);
   }
+#endif
   return state;
 }
 
