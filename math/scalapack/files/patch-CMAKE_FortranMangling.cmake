CMake-3.13.3 requires Source and Binary directories set:
https://gitlab.kitware.com/cmake/cmake/commit/27eb7c5bdb5bb8deefe1772675dc4819592bf036

--- CMAKE/FortranMangling.cmake.orig	2019-01-19 08:17:47 UTC
+++ CMAKE/FortranMangling.cmake
@@ -18,6 +18,7 @@ FUNCTION(COMPILE RESULT)
     EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND}  
          "-DCMAKE_Fortran_COMPILER=${CMAKE_Fortran_COMPILER}"
          "-DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}"
+	 "${PROJECT_SOURCE_DIR}/BLACS/INSTALL"
         WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/BLACS/INSTALL/        
         RESULT_VARIABLE RESVAR OUTPUT_VARIABLE LOG1 ERROR_VARIABLE LOG1
     )
