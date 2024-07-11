- fix the python version

--- cmake/DetectOptions.cmake.orig	2024-05-29 01:42:27 UTC
+++ cmake/DetectOptions.cmake
@@ -394,15 +394,15 @@ if(ADIOS2_USE_PIP)
 endif()
 
 if(ADIOS2_USE_PIP)
-  find_package(Python 3.8 REQUIRED COMPONENTS Interpreter Development.Module)
+  find_package(Python ${FREEBSD_PYTHON_VERSION} REQUIRED COMPONENTS Interpreter Development.Module)
   set(ADIOS2_HAVE_PIP TRUE)
 elseif(ADIOS2_USE_Python STREQUAL AUTO)
-  find_package(Python 3.8 COMPONENTS Interpreter Development)
+  find_package(Python ${FREEBSD_PYTHON_VERSION} COMPONENTS Interpreter Development)
   if(Python_FOUND AND ADIOS2_HAVE_MPI)
     find_package(PythonModule COMPONENTS mpi4py mpi4py/mpi4py.h)
   endif()
 elseif(ADIOS2_USE_Python)
-  find_package(Python 3.8 REQUIRED COMPONENTS Interpreter Development)
+  find_package(Python ${FREEBSD_PYTHON_VERSION} REQUIRED COMPONENTS Interpreter Development)
   if(ADIOS2_HAVE_MPI)
     find_package(PythonModule REQUIRED COMPONENTS mpi4py mpi4py/mpi4py.h)
   endif()
@@ -419,7 +419,7 @@ if(BUILD_TESTING AND NOT Python_Interpreter_FOUND)
 
 # Even if no python support, we still want the interpreter for tests
 if(BUILD_TESTING AND NOT Python_Interpreter_FOUND)
-  find_package(Python REQUIRED COMPONENTS Interpreter)
+  find_package(Python ${FREEBSD_PYTHON_VERSION} EXACT REQUIRED COMPONENTS Interpreter)
 endif()
 
 if(Python_Interpreter_FOUND)
