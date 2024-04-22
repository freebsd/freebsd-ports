--- ui/ozone/test/mock_platform_window_delegate.h.orig	2024-03-22 14:16:19 UTC
+++ ui/ozone/test/mock_platform_window_delegate.h
@@ -33,7 +33,7 @@ class MockPlatformWindowDelegate : public PlatformWind
   MOCK_METHOD2(OnWindowStateChanged,
                void(PlatformWindowState old_state,
                     PlatformWindowState new_state));
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   MOCK_METHOD1(OnWindowTiledStateChanged,
                void(WindowTiledEdges new_tiled_edges));
 #endif
