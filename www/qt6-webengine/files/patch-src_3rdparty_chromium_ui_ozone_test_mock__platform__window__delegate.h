--- src/3rdparty/chromium/ui/ozone/test/mock_platform_window_delegate.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/ozone/test/mock_platform_window_delegate.h
@@ -35,7 +35,7 @@ class MockPlatformWindowDelegate : public PlatformWind
   MOCK_METHOD2(OnWindowStateChanged,
                void(PlatformWindowState old_state,
                     PlatformWindowState new_state));
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   MOCK_METHOD1(OnWindowTiledStateChanged,
                void(WindowTiledEdges new_tiled_edges));
 #endif
