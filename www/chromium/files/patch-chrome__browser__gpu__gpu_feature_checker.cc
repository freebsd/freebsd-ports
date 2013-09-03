--- chrome/browser/gpu/gpu_feature_checker.cc.orig
+++ chrome/browser/gpu/gpu_feature_checker.cc
@@ -33,7 +33,7 @@ void GPUFeatureChecker::CheckGPUFeatureAvailability() {
   CHECK(content::BrowserThread::CurrentlyOn(content::BrowserThread::UI));
 
   bool finalized = true;
-#if defined(OS_LINUX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
   // On Windows and Mac, so far we can always make the final WebGL blacklisting
   // decision based on partial GPU info; on Linux, we need to launch the GPU
   // process to collect full GPU info and make the final decision.
