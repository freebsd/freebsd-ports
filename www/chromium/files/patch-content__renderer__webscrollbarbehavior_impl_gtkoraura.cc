--- content/renderer/webscrollbarbehavior_impl_gtkoraura.cc.orig	2015-04-14 18:18:54.000000000 -0400
+++ content/renderer/webscrollbarbehavior_impl_gtkoraura.cc	2015-04-28 09:19:06.077932000 -0400
@@ -13,7 +13,7 @@
       blink::WebScrollbarBehavior::Button mouseButton,
       bool shiftKeyPressed,
       bool altKeyPressed) {
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (mouseButton == blink::WebScrollbarBehavior::ButtonMiddle)
     return true;
 #endif
@@ -49,7 +49,7 @@
   // On most platforms, we should snap iff the event is outside our calculated
   // rect.  On Linux, however, we should not snap for events off the ends, but
   // not the sides, of the rect.
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   return isHorizontal ?
       (eventPoint.y < noSnapRect.y() || eventPoint.y >= noSnapRect.bottom()) :
       (eventPoint.x < noSnapRect.x() || eventPoint.x >= noSnapRect.right());
