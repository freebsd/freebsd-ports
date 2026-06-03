--- cmake/spheral/SpheralHandleTPL.cmake.orig	2026-04-01 08:49:15 UTC
+++ cmake/spheral/SpheralHandleTPL.cmake
@@ -95,7 +95,7 @@ function(Spheral_Handle_TPL lib_name TPL_CMAKE_DIR)
   if(NOT ${_is_imported})
     install(TARGETS ${lib_name}
       EXPORT spheral_cxx-targets
-      DESTINATION lib/cmake)
+      DESTINATION lib/cmake/spheral_cxx)
   endif()
   set_target_properties(${lib_name} PROPERTIES EXPORT_NAME spheral::${lib_name})
 endfunction()
