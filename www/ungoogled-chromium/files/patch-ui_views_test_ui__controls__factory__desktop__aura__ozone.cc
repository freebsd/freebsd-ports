--- ui/views/test/ui_controls_factory_desktop_aura_ozone.cc.orig	2023-12-23 12:33:28 UTC
+++ ui/views/test/ui_controls_factory_desktop_aura_ozone.cc
@@ -284,7 +284,7 @@ bool SendTouchEventsNotifyWhenDone(int action,
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 void ForceUseScreenCoordinatesOnce() {
   g_ozone_ui_controls_test_helper->ForceUseScreenCoordinatesOnce();
