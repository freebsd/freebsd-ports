--- cmake/ProcessOptions.cmake.orig	2022-01-21 18:01:36 UTC
+++ cmake/ProcessOptions.cmake
@@ -392,9 +392,9 @@ function( NEST_PROCESS_WITH_PYTHON )
   elseif ( ${with-python} STREQUAL "ON" )
 
     # Localize the Python interpreter and ABI
-    find_package( Python 3.8 QUIET COMPONENTS Interpreter Development.Module )
+    find_package( Python ${FREEBSD_PYTHON_VER} EXACT QUIET COMPONENTS Interpreter Development.Module )
     if ( NOT Python_FOUND )
-      find_package( Python 3.8 REQUIRED Interpreter Development )
+      find_package( Python ${FREEBSD_PYTHON_VER} EXACT REQUIRED Interpreter Development )
       string( CONCAT PYABI_WARN "Could not locate Python ABI"
         ", using shared libraries and header file instead."
         " Please clear your CMake cache and build folder and verify that CMake"
@@ -402,7 +402,7 @@ function( NEST_PROCESS_WITH_PYTHON )
       )
       message( WARNING "${PYABI_WARN}")
     else()
-      find_package( Python 3.8 REQUIRED Interpreter Development.Module )
+      find_package( Python ${FREEBSD_PYTHON_VER} EXACT REQUIRED Interpreter Development.Module )
     endif()
 
     if ( Python_FOUND )
@@ -432,7 +432,7 @@ function( NEST_PROCESS_WITH_PYTHON )
       set( Python_INCLUDE_DIRS "${Python_INCLUDE_DIRS}" PARENT_SCOPE )
       set( Python_LIBRARIES "${Python_LIBRARIES}" PARENT_SCOPE )
 
-      if ( cythonize-pynest )
+      if ( BUILD_PYTHON AND cythonize-pynest )
         # Need updated Cython because of a change in the C api in Python 3.7
         find_package( Cython 0.28.3 REQUIRED )
         if ( CYTHON_FOUND )
