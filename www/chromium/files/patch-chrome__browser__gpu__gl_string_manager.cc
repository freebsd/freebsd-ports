--- chrome/browser/gpu/gl_string_manager.cc.orig	2013-09-02 20:59:56.000000000 +0300
+++ chrome/browser/gpu/gl_string_manager.cc	2013-09-02 21:01:13.000000000 +0300
@@ -25,7 +25,7 @@
 
 void GLStringManager::Initialize() {
   // On MacOSX or Windows, preliminary GPUInfo is enough.
-#if defined(OS_LINUX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
   // We never remove this observer from GpuDataManager.
   content::GpuDataManager::GetInstance()->AddObserver(this);
 
