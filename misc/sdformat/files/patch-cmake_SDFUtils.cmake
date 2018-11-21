--- cmake/SDFUtils.cmake.orig	2018-11-21 00:24:14 UTC
+++ cmake/SDFUtils.cmake
@@ -148,9 +148,11 @@ macro (sdf_build_tests)
       message(FATAL_ERROR "Unsupported platform")
     endif()
 
-    add_dependencies(${BINARY_NAME}
-      gtest gtest_main ${sdf_target}
-      )
+    if (BUILD_TESTING)
+      add_dependencies(${BINARY_NAME}
+        gtest gtest_main ${sdf_target}
+        )
+    endif()
 
     link_directories(${IGNITION-MATH_LIBRARY_DIRS})
 
