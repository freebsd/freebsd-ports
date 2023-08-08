--- CMake/ITKModuleTest.cmake.orig	2019-08-03 09:25:42 UTC
+++ CMake/ITKModuleTest.cmake
@@ -244,6 +244,7 @@ endfunction()
 
 function(CreateGoogleTestDriver KIT KIT_LIBS KitTests)
   set(exe "${KIT}GTestDriver")
+  find_package(GTest)
   add_executable(${exe} ${KitTests} )
   target_link_libraries(${exe} ${KIT_LIBS} GTest::GTest GTest::Main)
   itk_module_target_label(${exe})
