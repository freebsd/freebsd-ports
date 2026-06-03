--- cmake/spheral/SpheralAddLibs.cmake.orig	2026-04-01 08:49:15 UTC
+++ cmake/spheral/SpheralAddLibs.cmake
@@ -138,7 +138,7 @@ function(spheral_add_cxx_library package_name _cxx_obj
     EXPORT        ${export_target_name})
 
   # Export Spheral target
-  install(EXPORT ${export_target_name} DESTINATION lib/cmake)
+  install(EXPORT ${export_target_name} DESTINATION lib/cmake/spheral_cxx)
 
   # Set the r-path of the C++ lib such that it is independent of the build dir when installed
   set_target_properties(Spheral_${package_name} PROPERTIES INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
