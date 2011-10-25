--- chrome/test/base/testing_browser_process.h.orig	2011-07-28 11:01:47.000000000 +0300
+++ chrome/test/base/testing_browser_process.h	2011-09-06 22:56:31.000000000 +0300
@@ -104,7 +104,7 @@
   virtual bool plugin_finder_disabled() const;
   virtual void CheckForInspectorFiles() {}
 
-#if (defined(OS_WIN) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
+#if (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
   virtual void StartAutoupdateTimer() {}
 #endif
 
