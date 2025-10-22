--- chrome/browser/ui/views/tabs/tab_style_views.cc.orig	2025-10-21 16:57:35 UTC
+++ chrome/browser/ui/views/tabs/tab_style_views.cc
@@ -557,7 +557,7 @@ float TabStyleViewsImpl::GetCurrentActiveOpacity() con
   if (!IsHoverAnimationActive()) {
     return base_opacity;
   }
-  return std::lerp(base_opacity, GetHoverOpacity(), GetHoverAnimationValue());
+  return std::lerp(base_opacity, GetHoverOpacity(), static_cast<float>(GetHoverAnimationValue()));
 }
 
 TabActive TabStyleViewsImpl::GetApparentActiveState() const {
