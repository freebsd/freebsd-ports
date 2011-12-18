--- xbmc/cores/VideoRenderers/LinuxRendererGL.cpp.orig
+++ xbmc/cores/VideoRenderers/LinuxRendererGL.cpp
@@ -159,6 +159,10 @@ CLinuxRendererGL::CLinuxRendererGL()
   m_rgbPbo = 0;
 
   m_dllSwScale = new DllSwScale;
+
+#ifdef __FreeBSD__
+  m_tid = NULL;
+#endif
 }
 
 CLinuxRendererGL::~CLinuxRendererGL()
@@ -247,6 +251,9 @@ bool CLinuxRendererGL::ValidateRenderTar
       (this->*m_textureCreate)(i);
 
     m_bValidated = true;
+#ifdef __FreeBSD__
+    m_tid = pthread_self();
+#endif
     return true;
   }
   return false;
@@ -716,6 +723,9 @@ unsigned int CLinuxRendererGL::PreInit()
   CSingleLock lock(g_graphicsContext);
   m_bConfigured = false;
   m_bValidated = false;
+#ifdef __FreeBSD__ // XXX Will this leak?  It's needed to avoid crashes... :(
+  if (pthread_self() == m_tid)
+#endif
   UnInit();
   m_resolution = g_guiSettings.m_LookAndFeelResolution;
   if ( m_resolution == RES_WINDOW )
