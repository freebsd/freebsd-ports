--- chrome/browser/ui/views/tabs/tab_style_views.cc.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/ui/views/tabs/tab_style_views.cc
@@ -627,7 +627,7 @@ float TabStyleViewsImpl::GetCurrentActiveOpacity() con
   if (!IsHoverAnimationActive()) {
     return base_opacity;
   }
-  return std::lerp(base_opacity, GetHoverOpacity(), GetHoverAnimationValue());
+  return std::lerp(base_opacity, GetHoverOpacity(), static_cast<float>(GetHoverAnimationValue()));
 }
 
 TabStyle::TabColors TabStyleViewsImpl::CalculateTargetColors() const {
