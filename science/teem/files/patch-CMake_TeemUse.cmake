-- Skip the removed CMAKE_IMPORT_BUILD_SETTINGS command (CMP0033) so that
-- downstream TeemUse.cmake does not fail with CMake 4.0+.

--- CMake/TeemUse.cmake.orig	2024-04-05 00:00:00 UTC
+++ CMake/TeemUse.cmake
@@ -31,6 +31,4 @@

 # Load the compiler settings used for Teem.
 IF(Teem_BUILD_SETTINGS_FILE)
-  INCLUDE(CMakeImportBuildSettings)
-  CMAKE_IMPORT_BUILD_SETTINGS(${Teem_BUILD_SETTINGS_FILE})
 ENDIF(Teem_BUILD_SETTINGS_FILE)
