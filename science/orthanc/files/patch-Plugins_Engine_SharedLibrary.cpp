--- Plugins/Engine/SharedLibrary.cpp.orig	2015-02-12 13:47:38 UTC
+++ Plugins/Engine/SharedLibrary.cpp
@@ -36,7 +36,7 @@
 
 #if defined(_WIN32)
 #include <windows.h>
-#elif defined(__linux) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD_kernel__)
+#elif defined(__linux) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD_kernel__) || defined(__FreeBSD__)
 #include <dlfcn.h>
 #else
 #error Support your platform here
@@ -58,7 +58,7 @@ namespace Orthanc
       throw OrthancException(ErrorCode_SharedLibrary);
     }
 
-#elif defined(__linux) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD_kernel__)
+#elif defined(__linux) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD_kernel__) || defined(__FreeBSD__)
     handle_ = ::dlopen(path.c_str(), RTLD_NOW);
     if (handle_ == NULL) 
     {
@@ -84,7 +84,7 @@ namespace Orthanc
     {
 #if defined(_WIN32)
       ::FreeLibrary((HMODULE)handle_);
-#elif defined(__linux) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD_kernel__)
+#elif defined(__linux) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD_kernel__) || defined(__FreeBSD__)
       ::dlclose(handle_);
 #else
 #error Support your platform here
@@ -102,7 +102,7 @@ namespace Orthanc
 
 #if defined(_WIN32)
     return ::GetProcAddress((HMODULE)handle_, name.c_str());
-#elif defined(__linux) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD_kernel__)
+#elif defined(__linux) || (defined(__APPLE__) && defined(__MACH__)) || defined(__FreeBSD_kernel__) || defined(__FreeBSD__)
     return ::dlsym(handle_, name.c_str());
 #else
 #error Support your platform here
