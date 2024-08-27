--- chrome/browser/ui/views/tabs/tab_style_views.cc.orig	2024-08-27 06:28:16 UTC
+++ chrome/browser/ui/views/tabs/tab_style_views.cc
@@ -550,7 +550,7 @@ float TabStyleViewsImpl::GetCurrentActiveOpacity() con
   if (!IsHoverAnimationActive()) {
     return base_opacity;
   }
-  return std::lerp(base_opacity, GetHoverOpacity(), GetHoverAnimationValue());
+  return std::lerp(base_opacity, GetHoverOpacity(), static_cast<float>(GetHoverAnimationValue()));
 }
 
 TabActive TabStyleViewsImpl::GetApparentActiveState() const {
