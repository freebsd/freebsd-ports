--- content/renderer/webscrollbarbehavior_impl_gtkoraura.cc.orig	2016-10-06 04:02:19.000000000 +0300
+++ content/renderer/webscrollbarbehavior_impl_gtkoraura.cc	2016-10-13 07:18:08.506709000 +0300
@@ -14,7 +14,7 @@
       blink::WebPointerProperties::Button mouseButton,
       bool shiftKeyPressed,
       bool altKeyPressed) {
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
   if (mouseButton == blink::WebPointerProperties::Button::Middle)
     return true;
 #endif
@@ -50,7 +50,7 @@
   // On most platforms, we should snap iff the event is outside our calculated
   // rect.  On Linux, however, we should not snap for events off the ends, but
   // not the sides, of the rect.
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   return isHorizontal ?
       (eventPoint.y < noSnapRect.y() || eventPoint.y >= noSnapRect.bottom()) :
       (eventPoint.x < noSnapRect.x() || eventPoint.x >= noSnapRect.right());
