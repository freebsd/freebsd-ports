--- ui/ozone/public/ozone_ui_controls_test_helper.h.orig	2025-05-07 06:48:23 UTC
+++ ui/ozone/public/ozone_ui_controls_test_helper.h
@@ -62,7 +62,7 @@ class OzoneUIControlsTestHelper {
   // aura::Window.
   virtual bool MustUseUiControlsForMoveCursorTo() = 0;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual void ForceUseScreenCoordinatesOnce();
 #endif
 };
