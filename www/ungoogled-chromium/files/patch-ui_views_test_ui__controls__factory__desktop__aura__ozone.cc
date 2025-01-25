--- ui/views/test/ui_controls_factory_desktop_aura_ozone.cc.orig	2025-01-25 09:34:31 UTC
+++ ui/views/test/ui_controls_factory_desktop_aura_ozone.cc
@@ -237,7 +237,7 @@ bool SendMouseClick(MouseButton type, gfx::NativeWindo
                          window_hint);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 void ForceUseScreenCoordinatesOnce() {
   g_ozone_ui_controls_test_helper->ForceUseScreenCoordinatesOnce();
