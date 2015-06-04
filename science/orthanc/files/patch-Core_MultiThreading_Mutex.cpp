--- Core/MultiThreading/Mutex.cpp.orig	2015-02-12 13:47:38 UTC
+++ Core/MultiThreading/Mutex.cpp
@@ -37,7 +37,7 @@
 
 #if defined(_WIN32)
 #include <windows.h>
-#elif defined(__linux) || defined(__FreeBSD_kernel__) || defined(__APPLE__)
+#elif defined(__linux) || defined(__FreeBSD_kernel__) || defined(__APPLE__) || defined(__FreeBSD__)
 #include <pthread.h>
 #else
 #error Support your platform here
@@ -75,7 +75,7 @@ namespace Orthanc
   }
 
 
-#elif defined(__linux) || defined(__FreeBSD_kernel__) || defined(__APPLE__)
+#elif defined(__linux) || defined(__FreeBSD_kernel__) || defined(__APPLE__) || defined(__FreeBSD__)
 
   struct Mutex::PImpl
   {
