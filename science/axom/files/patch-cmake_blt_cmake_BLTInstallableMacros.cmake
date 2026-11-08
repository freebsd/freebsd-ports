-- Make blt_patch_target() use the INTERFACE keyword (instead of PUBLIC) when
-- patching real (non-BLT-created) IMPORTED targets, not just INTERFACE_LIBRARY
-- targets.
-- Needed because axom's SetupAxomThirdParty.cmake calls
-- blt_patch_target(NAME mfem DEPENDS_ON mpi) on the "mfem" target that is now a
-- genuine CMake IMPORTED target exported directly by math/mfem's own
-- MFEMConfig.cmake (rather than one created via blt_import_library()).  CMake
-- unconditionally rejects any target_link_libraries() keyword other than
-- INTERFACE for IMPORTED targets, so the unpatched macro aborts configure with:
--   "IMPORTED library can only be used with the INTERFACE keyword of
--   target_link_libraries"
-- See https://github.com/LLNL/axom/issues (no upstream issue number found yet
-- for this specific BLT/MFEM CMake-config interaction as of axom 0.15.0).

--- cmake/blt/cmake/BLTInstallableMacros.cmake.orig	2026-10-01 16:29:17 UTC
+++ cmake/blt/cmake/BLTInstallableMacros.cmake
@@ -627,10 +627,14 @@ macro(blt_patch_target)
         message(FATAL_ERROR "blt_patch_target() NAME argument must be a native CMake target")
     endif()
 
-    # Default to public scope, unless it's an interface library
+    # Default to public scope, unless it's an interface library.
+    # Real (non-BLT-created) IMPORTED targets also require the INTERFACE
+    # keyword: CMake forbids any other keyword (PUBLIC/PRIVATE) on
+    # target_link_libraries() for IMPORTED targets.
     set(_scope PUBLIC)
     get_target_property(_target_type ${arg_NAME} TYPE)
-    if("${_target_type}" STREQUAL "INTERFACE_LIBRARY")
+    get_target_property(_target_imported ${arg_NAME} IMPORTED)
+    if("${_target_type}" STREQUAL "INTERFACE_LIBRARY" OR _target_imported)
         set(_scope INTERFACE)
     endif()
 
