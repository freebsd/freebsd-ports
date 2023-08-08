--- CMake/ITKModuleExternal.cmake.orig	2022-11-18 08:12:04 UTC
+++ CMake/ITKModuleExternal.cmake
@@ -221,6 +221,8 @@ endif()
 # Create target to download data from the ITKData group.  This must come after
 # all tests have been added that reference the group, so we put it last.
 if(NOT TARGET ITKData)
-  include(ExternalData)
+  if (BUILD_TESTING)
+    include(ExternalData)
+  endif()
   ExternalData_Add_Target(ITKData)
 endif()
