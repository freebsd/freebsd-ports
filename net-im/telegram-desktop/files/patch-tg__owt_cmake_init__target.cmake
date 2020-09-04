--- tg_owt/cmake/init_target.cmake.orig	2020-08-30 09:41:57 UTC
+++ tg_owt/cmake/init_target.cmake
@@ -10,7 +10,7 @@ function(init_target target_name) # init_target(my_tar
     elseif (APPLE)
         target_compile_features(${target_name} PUBLIC cxx_std_14)
     else()
-        target_compile_features(${target_name} PUBLIC cxx_std_20)
+        target_compile_features(${target_name} PUBLIC cxx_std_17)
     endif()
     if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
         set_target_properties(${target_name} PROPERTIES
