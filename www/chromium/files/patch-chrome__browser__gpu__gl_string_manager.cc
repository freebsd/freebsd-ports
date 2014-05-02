--- ./chrome/browser/gpu/gl_string_manager.cc.orig	2014-04-24 22:35:12.000000000 +0200
+++ ./chrome/browser/gpu/gl_string_manager.cc	2014-04-24 23:23:42.000000000 +0200
@@ -25,7 +25,7 @@
 
 void GLStringManager::Initialize() {
   // On MacOSX or Windows, preliminary GPUInfo is enough.
-#if defined(OS_LINUX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
   // We never remove this observer from GpuDataManager.
   content::GpuDataManager::GetInstance()->AddObserver(this);
 
