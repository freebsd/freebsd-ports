-- Install the spheral_cxx CMake export files under a package-specific
-- subdirectory to avoid conflicts with other ports.

--- cmake/spheral/SpheralAddLibs.cmake.orig	2026-06-23 16:46:22 UTC
+++ cmake/spheral/SpheralAddLibs.cmake
@@ -146,7 +146,7 @@ function(spheral_add_cxx_library package_name _cxx_obj
     EXPORT        ${export_target_name})
 
   # Export Spheral target
-  install(EXPORT ${export_target_name} DESTINATION lib/cmake)
+  install(EXPORT ${export_target_name} DESTINATION lib/cmake/spheral_cxx)
 endfunction()
 
 #----------------------------------------------------------------------------------------
