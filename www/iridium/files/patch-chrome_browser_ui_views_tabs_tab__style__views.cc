--- chrome/browser/ui/views/tabs/tab_style_views.cc.orig	2025-05-07 06:48:23 UTC
+++ chrome/browser/ui/views/tabs/tab_style_views.cc
@@ -545,7 +545,7 @@ float TabStyleViewsImpl::GetCurrentActiveOpacity() con
   if (!IsHoverAnimationActive()) {
     return base_opacity;
   }
-  return std::lerp(base_opacity, GetHoverOpacity(), GetHoverAnimationValue());
+  return std::lerp(base_opacity, GetHoverOpacity(), static_cast<float>(GetHoverAnimationValue()));
 }
 
 TabActive TabStyleViewsImpl::GetApparentActiveState() const {
