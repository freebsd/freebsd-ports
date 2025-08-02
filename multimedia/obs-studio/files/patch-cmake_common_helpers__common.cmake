--- cmake/common/helpers_common.cmake.orig	2025-08-01 04:18:14 UTC
+++ cmake/common/helpers_common.cmake
@@ -467,6 +467,9 @@ function(add_obs_plugin target)
     set(found_architecture TRUE)
   else()
     foreach(architecture IN LISTS _AOP_ARCHITECTURES)
+      if (${architecture} STREQUAL x86_64)
+      	set(architecture "amd64") # the x86_64 is called amd64 on BSDs
+      endif()
       if(OS_WINDOWS)
         if("${architecture}" STREQUAL CMAKE_VS_PLATFORM_NAME)
           set(found_architecture TRUE)
