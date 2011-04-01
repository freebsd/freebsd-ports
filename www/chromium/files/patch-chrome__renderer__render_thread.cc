--- ./chrome/renderer/render_thread.cc.orig	2010-12-16 02:11:59.000000000 +0100
+++ ./chrome/renderer/render_thread.cc	2010-12-20 20:15:08.000000000 +0100
@@ -972,7 +972,7 @@
 }
 
 void RenderThread::IdleHandler() {
-#if (defined(OS_WIN) || defined(OS_LINUX)) && defined(USE_TCMALLOC)
+#if !defined(OS_MACOSX) && defined(USE_TCMALLOC)
   MallocExtension::instance()->ReleaseFreeMemory();
 #endif
 
@@ -1048,7 +1048,7 @@
   while (!v8::V8::IdleNotification()) {
   }
 
-#if (defined(OS_WIN) || defined(OS_LINUX)) && defined(USE_TCMALLOC)
+#if !defined(OS_MACOSX) && defined(USE_TCMALLOC)
   // Tell tcmalloc to release any free pages it's still holding.
   MallocExtension::instance()->ReleaseFreeMemory();
 #endif
