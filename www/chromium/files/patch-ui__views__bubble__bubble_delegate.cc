--- ui/views/bubble/bubble_delegate.cc.orig	2015-04-14 18:31:23.000000000 -0400
+++ ui/views/bubble/bubble_delegate.cc	2015-04-28 08:17:15.923055000 -0400
@@ -104,7 +104,7 @@
   // the parent frame and let DWM handle compositing.  If not, then we don't
   // want to allow the bubble to extend the frame because it will be clipped.
   bubble_delegate->set_adjust_if_offscreen(ui::win::IsAeroGlassEnabled());
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Linux clips bubble windows that extend outside their parent window bounds.
   bubble_delegate->set_adjust_if_offscreen(false);
 #endif
