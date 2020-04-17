--- src/ngraph/runtime/backend.cpp.orig	2020-04-17 02:14:53 UTC
+++ src/ngraph/runtime/backend.cpp
@@ -16,7 +16,7 @@
 
 #ifdef _WIN32
 #include <windows.h>
-#elif defined(__linux) || defined(__APPLE__)
+#elif defined(__linux) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <dlfcn.h>
 #endif
 
@@ -48,7 +48,7 @@ static string find_my_pathname()
     path = file_util::get_directory(path);
     path += "/";
     return path;
-#elif defined(__linux) || defined(__APPLE__)
+#elif defined(__linux) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
     Dl_info dl_info;
     dladdr(reinterpret_cast<void*>(find_my_pathname), &dl_info);
     return dl_info.dli_fname;
