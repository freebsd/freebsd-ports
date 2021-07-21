--- cmake/external.cmake.orig	2021-06-27 05:27:48 UTC
+++ cmake/external.cmake
@@ -109,7 +109,7 @@ endfunction()
 # libabsl
 # HINT: System abseil should be built with -DCMAKE_CXX_STANDARD=17
 function(link_libabsl target_name)
-    if (TG_OWT_PACKAGED_BUILD)
+    if (0)
         find_package(absl)
         set(absl_FOUND ${absl_FOUND} PARENT_SCOPE)
         if (absl_FOUND)
