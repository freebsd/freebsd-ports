--- content/renderer/render_view.h.orig	2010-12-16 02:11:59.000000000 +0100
+++ content/renderer/render_view.h	2010-12-20 20:15:08.000000000 +0100
@@ -1114,7 +1114,7 @@
   // periodic timer so we don't send too many messages.
   void SyncNavigationState();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   void UpdateFontRenderingFromRendererPrefs();
 #else
   void UpdateFontRenderingFromRendererPrefs() {}
