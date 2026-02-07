Fix build with CMake >= 3.29.0. Support for the Comeau compiler was removed.

--- Modules/ThirdParty/VNL/src/vxl/vcl/tests/test_preprocessor.cxx.orig	2022-11-24 13:15:41 UTC
+++ Modules/ThirdParty/VNL/src/vxl/vcl/tests/test_preprocessor.cxx
@@ -9,8 +9,7 @@ int test_preprocessor_main(int /*argc*/,char* /*argv*/
 int test_preprocessor_main(int /*argc*/,char* /*argv*/[])
 {
   constexpr unsigned compiler_count
-      = VXL_COMPILER_IS_Comeau
-        + VXL_COMPILER_IS_Intel
+      = VXL_COMPILER_IS_Intel
         + VXL_COMPILER_IS_PathScale
         + VXL_COMPILER_IS_Embarcadero
         + VXL_COMPILER_IS_Borland
