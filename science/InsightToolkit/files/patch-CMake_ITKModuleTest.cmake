--- CMake/ITKModuleTest.cmake.orig	2022-11-17 05:24:11 UTC
+++ CMake/ITKModuleTest.cmake
@@ -193,6 +193,7 @@ endfunction()
 
 function(CreateGoogleTestDriver KIT KIT_LIBS KitTests)
   set(exe "${KIT}GTestDriver")
+  find_package(GTest)
   add_executable(${exe} ${KitTests})
   target_link_libraries(${exe} ${KIT_LIBS} GTest::GTest GTest::Main)
   itk_module_target_label(${exe})
