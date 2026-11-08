-- Replace get_target_property(LOCATION) with target names for CMake 4.0 compatibility.
-- CMake 4.0 removed support for the LOCATION target property (CMP0026 OLD).
-- add_test() resolves target names to their built executable paths automatically.

--- tests/settings.cmake.orig	2026-08-27 09:01:34 UTC
+++ tests/settings.cmake
@@ -8,12 +8,12 @@ if( ENABLE_INSTALL_TOOLS )
 # - cmp (strict binary comparison)

 if( ENABLE_INSTALL_TOOLS )
-  get_target_property( CMD_INT         int         LOCATION )
-  get_target_property( CMD_GG_GRIDNAME gg_gridname LOCATION )
+  set( CMD_INT         int )
+  set( CMD_GG_GRIDNAME gg_gridname )
 endif()

 if( TARGET grib_compare )
-  get_target_property( CMD_GRIB_COMPARE grib_compare LOCATION )
+  set( CMD_GRIB_COMPARE grib_compare )
 endif()
 if( NOT CMD_GRIB_COMPARE )
   find_program( CMD_GRIB_COMPARE grib_compare NO_DEFAULT_PATH HINTS "${eccodes_BASE_DIR}" PATH_SUFFIXES "bin" )
