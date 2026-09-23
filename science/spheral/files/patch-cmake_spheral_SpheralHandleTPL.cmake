--- cmake/spheral/SpheralHandleTPL.cmake.orig	2026-06-23 16:46:22 UTC
+++ cmake/spheral/SpheralHandleTPL.cmake
@@ -97,7 +97,7 @@ function(Spheral_Handle_TPL lib_name TPL_CMAKE_DIR)
   if(NOT ${_is_imported})
     install(TARGETS ${lib_name}
       EXPORT spheral_cxx-targets
-      DESTINATION lib/cmake)
+      DESTINATION lib/cmake/spheral_cxx)
   endif()
   set_target_properties(${lib_name} PROPERTIES EXPORT_NAME spheral::${lib_name})
 endfunction()
