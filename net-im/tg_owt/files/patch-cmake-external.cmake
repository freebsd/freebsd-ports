--- cmake/external.cmake.orig	2022-05-17 12:30:55.086821000 -0400
+++ cmake/external.cmake	2022-05-17 12:31:34.766999000 -0400
@@ -122,6 +122,9 @@
                 absl::type_traits
                 absl::variant
             )
+	    find_package(PkgConfig REQUIRED)
+	    pkg_check_modules(ABSL REQUIRED QUIET absl_flags)
+	    target_include_directories(${target_name} PRIVATE ${ABSL_INCLUDE_DIRS})
         endif()
     endif()
     if (NOT absl_FOUND)
