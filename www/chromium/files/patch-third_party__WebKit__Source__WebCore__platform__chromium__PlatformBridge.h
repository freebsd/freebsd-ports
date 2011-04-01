--- third_party/WebKit/Source/WebCore/platform/chromium/PlatformBridge.h.orig	2011-03-20 22:02:04.218736318 +0200
+++ third_party/WebKit/Source/WebCore/platform/chromium/PlatformBridge.h	2011-03-20 22:02:04.401737230 +0200
@@ -264,7 +264,7 @@
         GraphicsContext*, int part, int state, int classicState, const IntRect&);
     static void paintProgressBar(
         GraphicsContext*, const IntRect& barRect, const IntRect& valueRect, bool determinate, double animatedSeconds);
-#elif OS(LINUX)
+#elif OS(LINUX) || OS(FREEBSD)
     // The UI part which is being accessed.
     enum ThemePart {
         // ScrollbarTheme parts
