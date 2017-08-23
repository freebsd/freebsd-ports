--- content/browser/gpu/gpu_feature_checker_impl.cc.orig	2017-08-10 16:07:56.429478000 +0200
+++ content/browser/gpu/gpu_feature_checker_impl.cc	2017-08-10 16:08:25.522586000 +0200
@@ -39,7 +39,7 @@
   CHECK(BrowserThread::CurrentlyOn(BrowserThread::UI));
 
   bool finalized = true;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Windows and Mac, so far we can always make the final WebGL blacklisting
   // decision based on partial GPU info; on Linux, we need to launch the GPU
   // process to collect full GPU info and make the final decision.
