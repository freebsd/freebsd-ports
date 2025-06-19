--- chrome/browser/ui/views/tabs/tab_style_views.cc.orig	2025-06-19 07:37:57 UTC
+++ chrome/browser/ui/views/tabs/tab_style_views.cc
@@ -563,7 +563,7 @@ float TabStyleViewsImpl::GetCurrentActiveOpacity() con
   if (!IsHoverAnimationActive()) {
     return base_opacity;
   }
-  return std::lerp(base_opacity, GetHoverOpacity(), GetHoverAnimationValue());
+  return std::lerp(base_opacity, GetHoverOpacity(), static_cast<float>(GetHoverAnimationValue()));
 }
 
 TabActive TabStyleViewsImpl::GetApparentActiveState() const {
