--- content/renderer/webscrollbarbehavior_impl_gtkoraura.cc.orig	2016-03-25 13:04:49 UTC
+++ content/renderer/webscrollbarbehavior_impl_gtkoraura.cc
@@ -14,7 +14,7 @@ bool WebScrollbarBehaviorImpl::shouldCen
       blink::WebScrollbarBehavior::Button mouseButton,
       bool shiftKeyPressed,
       bool altKeyPressed) {
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (mouseButton == blink::WebScrollbarBehavior::ButtonMiddle)
     return true;
 #endif
@@ -50,7 +50,7 @@ bool WebScrollbarBehaviorImpl::shouldSna
   // On most platforms, we should snap iff the event is outside our calculated
   // rect.  On Linux, however, we should not snap for events off the ends, but
   // not the sides, of the rect.
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   return isHorizontal ?
       (eventPoint.y < noSnapRect.y() || eventPoint.y >= noSnapRect.bottom()) :
       (eventPoint.x < noSnapRect.x() || eventPoint.x >= noSnapRect.right());
