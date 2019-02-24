--- chrome/browser/browser_process_impl.cc.orig	2019-02-12 16:31:58.701630000 +0100
+++ chrome/browser/browser_process_impl.cc	2019-02-12 16:32:33.417312000 +0100
@@ -1485,7 +1485,7 @@
 }
 
 // Mac is currently not supported.
-#if (defined(OS_WIN) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
+#if (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 
 bool BrowserProcessImpl::IsRunningInBackground() const {
   // Check if browser is in the background.
@@ -1555,4 +1555,4 @@
   }
 }
 
-#endif  // (defined(OS_WIN) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
