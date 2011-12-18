--- xbmc/cores/VideoRenderers/LinuxRendererGL.h.orig
+++ xbmc/cores/VideoRenderers/LinuxRendererGL.h
@@ -228,6 +228,10 @@ protected:
   int m_currentField;
   int m_reloadShaders;
 
+#ifdef __FreeBSD__
+  pthread_t m_tid;
+#endif
+
   struct YUVPLANE
   {
     GLuint id;
