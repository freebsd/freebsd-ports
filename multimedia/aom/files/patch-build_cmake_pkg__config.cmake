- Limit internal dependencies to static library

--- build/cmake/pkg_config.cmake.orig	2022-06-17 17:46:18 UTC
+++ build/cmake/pkg_config.cmake
@@ -51,7 +51,7 @@ file(APPEND "${pkgconfig_file}" "Version: ${package_ve
   APPEND "${pkgconfig_file}"
   "Description: Alliance for Open Media AV1 codec library v${aom_version}.\n")
 file(APPEND "${pkgconfig_file}" "Version: ${package_version}\n")
-file(APPEND "${pkgconfig_file}" "Requires:")
+file(APPEND "${pkgconfig_file}" "Requires.private:")
 if(CONFIG_TUNE_VMAF)
   file(APPEND "${pkgconfig_file}" " libvmaf")
 endif()
