--- cmake/external.cmake.orig	2023-01-11 16:35:01 UTC
+++ cmake/external.cmake
@@ -120,6 +120,9 @@ function(link_libabsl target_name)
                 absl::type_traits
                 absl::variant
             )
+            find_package(PkgConfig REQUIRED)
+            pkg_check_modules(ABSL REQUIRED QUIET absl_flags)
+            target_include_directories(${target_name} PRIVATE ${ABSL_INCLUDE_DIRS})
         endif()
     endif()
     if (NOT absl_FOUND)
