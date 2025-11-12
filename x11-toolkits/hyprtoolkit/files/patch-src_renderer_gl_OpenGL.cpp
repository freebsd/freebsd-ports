--- src/renderer/gl/OpenGL.cpp.orig	2025-11-12 08:29:16 UTC
+++ src/renderer/gl/OpenGL.cpp
@@ -447,7 +447,7 @@ COpenGLRenderer::COpenGLRenderer(int drmFD) : m_drmFD(
 
     g_logger->log(HT_LOG_DEBUG, "DRM syncobj timeline support: {}", m_syncobjSupported ? "yes" : "no");
 #else
-    Debug::log(LOG, "DRM syncobj timeline support: no (not linux)");
+    g_logger->log(HT_LOG_DEBUG, "DRM syncobj timeline support: no (not linux)");
 #endif
 
 #ifdef HYPRTOOLKIT_DEBUG
