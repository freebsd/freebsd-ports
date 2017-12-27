--- config/SundialsFortran.cmake.orig	2017-11-07 23:47:45 UTC
+++ config/SundialsFortran.cmake
@@ -51,9 +51,9 @@ if(CMAKE_Fortran_COMPILER)
       (NOT "${ENV_FCFLAGS}" STREQUAL "") AND
       ("${CMAKE_Fortran_FLAGS}" STREQUAL ""))
     # check if environment variables are equal
-    IF (NOT "${ENV_FFLAGS}" STREQUAL "${ENV_FCFLAGS}")
-      PRINT_ERROR("FFLAGS='${ENV_FFLAGS}' and FCFLAGS='${ENV_FCFLAGS}' are both set but are not equal.")
-    ENDIF()
+    #IF (NOT "${ENV_FFLAGS}" STREQUAL "${ENV_FCFLAGS}")
+    #  PRINT_ERROR("FFLAGS='${ENV_FFLAGS}' and FCFLAGS='${ENV_FCFLAGS}' are both set but are not equal.")
+    #ENDIF()
   ENDIF()
 
   # Enable the language for next steps
