-- Switch the bundled ecbuild policies to NEW behavior for CMP0026,
-- CMP0048 and CMP0068.  CMake 4.0 no longer allows OLD behavior for these
-- policies.

--- cmake/ecbuild_policies.cmake.orig	2024-04-05 00:00:00 UTC
+++ cmake/ecbuild_policies.cmake
@@ -25,7 +25,7 @@

 # Allow use of the LOCATION target property.
 if( POLICY CMP0026 )
-    cmake_policy( SET CMP0026 OLD )
+    cmake_policy( SET CMP0026 NEW )
 endif()

 # for macosx use @rpath in a target’s install name
@@ -46,7 +46,7 @@

 # Do not manage VERSION variables in project command
 if( POLICY CMP0048 )
-  cmake_policy( SET CMP0048 OLD )
+  cmake_policy( SET CMP0048 NEW )
 endif()

 # Disallow add_custom_command SOURCE signatures
@@ -67,7 +67,6 @@
 endif()

 # RPATH settings on macOS do not affect "install_name"
-# FTM, keep old behavior -- need to test if new behavior impacts binaries in build directory
 if( POLICY CMP0068 )
-    cmake_policy( SET CMP0068 OLD )
+    cmake_policy( SET CMP0068 NEW )
 endif()
