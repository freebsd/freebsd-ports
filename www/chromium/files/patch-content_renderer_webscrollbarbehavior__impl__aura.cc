--- content/renderer/webscrollbarbehavior_impl_aura.cc.orig	2017-06-05 19:03:07 UTC
+++ content/renderer/webscrollbarbehavior_impl_aura.cc
@@ -14,7 +14,7 @@ bool WebScrollbarBehaviorImpl::ShouldCenterOnThumb(
     blink::WebPointerProperties::Button mouseButton,
     bool shiftKeyPressed,
     bool altKeyPressed) {
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (mouseButton == blink::WebPointerProperties::Button::kMiddle)
     return true;
 #endif
@@ -29,7 +29,7 @@ bool WebScrollbarBehaviorImpl::ShouldSnapBackToDragOri
 // Disable snapback on desktop Linux to better integrate with the desktop
 // behavior.  Typically, Linux apps do not implement scrollbar snapback (this is
 // true for at least GTK and QT apps).
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   return false;
 #endif
 
