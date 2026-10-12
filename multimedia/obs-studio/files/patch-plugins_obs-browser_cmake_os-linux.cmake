--- plugins/obs-browser/cmake/os-linux.cmake.orig	2026-08-14 22:07:07 UTC
+++ plugins/obs-browser/cmake/os-linux.cmake
@@ -20,6 +20,7 @@ target_include_directories(browser-helpe
                                                   "${CMAKE_CURRENT_SOURCE_DIR}/obs-browser-page")
 
 target_link_libraries(browser-helper PRIVATE CEF::Wrapper CEF::Library)
+target_compile_features(browser-helper PRIVATE cxx_std_20)
 
 target_sources(obs-browser PRIVATE deps/ip-string-posix.cpp)
 
@@ -34,3 +35,11 @@ set_target_properties_obs(
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
