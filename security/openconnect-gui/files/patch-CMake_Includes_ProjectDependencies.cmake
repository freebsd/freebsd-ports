--- CMake/Includes/ProjectDependencies.cmake.orig	2021-02-18 00:27:05 UTC
+++ CMake/Includes/ProjectDependencies.cmake
@@ -36,7 +36,7 @@ if(UNIX)
         message(FATAL_ERROR "Libraru 'OpenConnect' not found! Install it vie e.g. 'brew install openconnect or 'dnf install openconnect'")
     endif()
     
-    #find_package(spdlog CONFIG REQUIRED)
+    find_package(spdlog CONFIG REQUIRED)
     
     set(CMAKE_THREAD_PREFER_PTHREAD ON)
     find_package(Threads REQUIRED)
