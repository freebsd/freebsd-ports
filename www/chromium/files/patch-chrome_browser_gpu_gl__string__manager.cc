--- chrome/browser/gpu/gl_string_manager.cc.orig	2016-04-08 16:02:07 UTC
+++ chrome/browser/gpu/gl_string_manager.cc
@@ -28,7 +28,7 @@ GLStringManager::~GLStringManager() {
 
 void GLStringManager::Initialize() {
   // On MacOSX or Windows, preliminary GPUInfo is enough.
-#if defined(OS_LINUX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
   // We never remove this observer from GpuDataManager.
   content::GpuDataManager::GetInstance()->AddObserver(this);
 
