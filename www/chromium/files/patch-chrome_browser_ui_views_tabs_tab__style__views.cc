--- chrome/browser/ui/views/tabs/tab_style_views.cc.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/ui/views/tabs/tab_style_views.cc
@@ -563,7 +563,7 @@ float TabStyleViewsImpl::GetCurrentActiveOpacity() con
   if (!IsHoverAnimationActive()) {
     return base_opacity;
   }
-  return std::lerp(base_opacity, GetHoverOpacity(), GetHoverAnimationValue());
+  return std::lerp(base_opacity, GetHoverOpacity(), static_cast<float>(GetHoverAnimationValue()));
 }
 
 bool TabStyleViewsImpl::IsApparentlyActive() const {
