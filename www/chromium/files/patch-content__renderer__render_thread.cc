--- content/renderer/render_thread.cc.orig	2011-05-06 12:02:55.000000000 +0300
+++ content/renderer/render_thread.cc	2011-06-04 15:55:04.481380035 +0300
@@ -607,7 +607,7 @@
 }
 
 void RenderThread::IdleHandler() {
-#if (defined(OS_WIN) || defined(OS_LINUX)) && defined(USE_TCMALLOC)
+#if !defined(OS_MACOSX) && defined(USE_TCMALLOC)
   MallocExtension::instance()->ReleaseFreeMemory();
 #endif
 
