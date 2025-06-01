--- chrome/browser/ui/views/tabs/tab_style_views.cc.orig	2025-05-31 17:16:41 UTC
+++ chrome/browser/ui/views/tabs/tab_style_views.cc
@@ -563,7 +563,7 @@ float TabStyleViewsImpl::GetCurrentActiveOpacity() con
   if (!IsHoverAnimationActive()) {
     return base_opacity;
   }
-  return std::lerp(base_opacity, GetHoverOpacity(), GetHoverAnimationValue());
+  return std::lerp(base_opacity, GetHoverOpacity(), static_cast<float>(GetHoverAnimationValue()));
 }
 
 TabActive TabStyleViewsImpl::GetApparentActiveState() const {
