--- ./Source/WebCore/platform/graphics/surfaces/GraphicsSurface.h.orig	2012-12-18 20:04:31.000000000 +0100
+++ ./Source/WebCore/platform/graphics/surfaces/GraphicsSurface.h	2012-12-28 13:00:05.846909692 +0100
@@ -36,7 +36,7 @@
 typedef IOSurfaceRef PlatformGraphicsSurface;
 #endif
 
-#if OS(LINUX)
+#if OS(LINUX) || OS(FREEBSD)
 typedef uint32_t PlatformGraphicsSurface;
 #endif
 
