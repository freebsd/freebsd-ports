--- chrome/browser/ui/views/tabs/tab_style_views.cc.orig	2026-02-15 10:01:45 UTC
+++ chrome/browser/ui/views/tabs/tab_style_views.cc
@@ -557,7 +557,7 @@ float TabStyleViewsImpl::GetCurrentActiveOpacity() con
   if (!IsHoverAnimationActive()) {
     return base_opacity;
   }
-  return std::lerp(base_opacity, GetHoverOpacity(), GetHoverAnimationValue());
+  return std::lerp(base_opacity, GetHoverOpacity(), static_cast<float>(GetHoverAnimationValue()));
 }
 
 bool TabStyleViewsImpl::IsApparentlyActive() const {
