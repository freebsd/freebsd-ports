--- chrome/test/testing_browser_process.h.orig	2011-04-15 11:02:00.000000000 +0300
+++ chrome/test/testing_browser_process.h	2011-04-16 21:00:37.080070649 +0300
@@ -49,7 +49,7 @@
 
   virtual IOThread* io_thread();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   virtual base::Thread* background_x11_thread();
 #endif
 
@@ -120,7 +120,7 @@
 
   virtual void CheckForInspectorFiles() {}
 
-#if (defined(OS_WIN) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
+#if (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
   virtual void StartAutoupdateTimer() {}
 #endif
 
