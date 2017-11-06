--- chrome/browser/gpu/gl_string_manager.cc.orig	2017-04-19 19:06:29 UTC
+++ chrome/browser/gpu/gl_string_manager.cc
@@ -33,7 +33,7 @@ GLStringManager::~GLStringManager() {
 
 void GLStringManager::Initialize() {
   // On MacOSX or Windows, preliminary GPUInfo is enough.
-#if defined(OS_LINUX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
   // We never remove this observer from GpuDataManager.
   content::GpuDataManager::GetInstance()->AddObserver(this);
 
