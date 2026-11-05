--- plugins/obs-browser/cmake/os-linux.cmake.orig	2026-10-29 21:06:38 UTC
+++ plugins/obs-browser/cmake/os-linux.cmake
@@ -36,3 +36,11 @@ set_target_properties_obs(
              PREFIX ""
              OUTPUT_NAME obs-browser-page)
 # cmake-format: on
+
+if(OS_FREEBSD)
+  cmake_path(GET CEF_LIBRARY_RELEASE PARENT_PATH cef_library_dir)
+  set_target_properties(obs-browser PROPERTIES BUILD_RPATH "$ORIGIN/;${cef_library_dir}"
+                                               INSTALL_RPATH "$ORIGIN/;${cef_library_dir}")
+  set_target_properties(browser-helper PROPERTIES BUILD_RPATH "$ORIGIN/;${cef_library_dir}"
+                                                  INSTALL_RPATH "$ORIGIN/;${cef_library_dir}")
+endif()
