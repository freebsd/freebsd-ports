- fix the python version

--- cmake/DetectOptions.cmake.orig	2023-03-30 20:01:59 UTC
+++ cmake/DetectOptions.cmake
@@ -351,12 +351,12 @@ if(NOT SHARED_LIBS_SUPPORTED)
 endif()
 
 if(ADIOS2_USE_Python STREQUAL AUTO)
-  find_package(Python 3 COMPONENTS Interpreter Development NumPy)
+  find_package(Python ${FREEBSD_PYTHON_VERSION} EXACT COMPONENTS Interpreter Development NumPy)
   if(Python_FOUND AND ADIOS2_HAVE_MPI)
     find_package(PythonModule COMPONENTS mpi4py mpi4py/mpi4py.h)
   endif()
 elseif(ADIOS2_USE_Python)
-  find_package(Python 3 REQUIRED COMPONENTS Interpreter Development NumPy)
+  find_package(Python ${FREEBSD_PYTHON_VERSION} EXACT REQUIRED COMPONENTS Interpreter Development NumPy)
   if(ADIOS2_HAVE_MPI)
     find_package(PythonModule REQUIRED COMPONENTS mpi4py mpi4py/mpi4py.h)
   endif()
@@ -373,7 +373,7 @@ endif()
 
 # Even if no python support, we still want the interpreter for tests
 if(BUILD_TESTING AND NOT Python_Interpreter_FOUND)
-  find_package(Python REQUIRED COMPONENTS Interpreter)
+  find_package(Python ${FREEBSD_PYTHON_VERSION} EXACT REQUIRED COMPONENTS Interpreter)
 endif()
 
 if(Python_Interpreter_FOUND)
