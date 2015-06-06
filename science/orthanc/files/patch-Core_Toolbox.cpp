--- Core/Toolbox.cpp.orig	2015-02-12 13:47:38 UTC
+++ Core/Toolbox.cpp
@@ -59,7 +59,7 @@
 #include <limits.h>      /* PATH_MAX */
 #endif
 
-#if defined(__linux) || defined(__FreeBSD_kernel__)
+#if defined(__linux) || defined(__FreeBSD_kernel__) || defined(__FreeBSD__)
 #include <limits.h>      /* PATH_MAX */
 #include <signal.h>
 #include <unistd.h>
@@ -116,7 +116,7 @@ namespace Orthanc
   {
 #if defined(_WIN32)
     ::Sleep(static_cast<DWORD>(microSeconds / static_cast<uint64_t>(1000)));
-#elif defined(__linux) || defined(__APPLE__) || defined(__FreeBSD_kernel__)
+#elif defined(__linux) || defined(__APPLE__) || defined(__FreeBSD_kernel__) || defined(__FreeBSD__)
     usleep(microSeconds);
 #else
 #error Support your platform here
@@ -503,7 +503,7 @@ namespace Orthanc
     return std::string(&buffer[0]);
   }
 
-#elif defined(__linux) || defined(__FreeBSD_kernel__)
+#elif defined(__linux) || defined(__FreeBSD_kernel__) || defined(__FreeBSD__)
   static std::string GetPathToExecutableInternal()
   {
     std::vector<char> buffer(PATH_MAX + 1);
@@ -633,7 +633,7 @@ namespace Orthanc
     result.reserve(source.size() + 1);
     for (size_t i = 0; i < source.size(); i++)
     {
-      if (source[i] < 128 && source[i] >= 0 && !iscntrl(source[i]))
+      if (source[i] <= 127 && source[i] >= 0 && !iscntrl(source[i]))
       {
         result.push_back(source[i]);
       }
