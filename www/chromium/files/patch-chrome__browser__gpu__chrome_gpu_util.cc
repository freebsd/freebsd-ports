--- chrome/browser/gpu/chrome_gpu_util.cc.orig	2013-09-02 20:57:36.000000000 +0300
+++ chrome/browser/gpu/chrome_gpu_util.cc	2013-09-02 20:59:37.000000000 +0300
@@ -36,7 +36,7 @@
 
 bool ShouldRunCompositingFieldTrial() {
 // Enable the field trial only on desktop OS's.
-#if !(defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX))
+#if !(defined(OS_WIN) || (defined(OS_POSIX) && !defined(OS_ANDROID)))
   return false;
 #endif
 
