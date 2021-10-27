--- cmake/ProcessOptions.cmake.orig	2021-10-21 05:42:49 UTC
+++ cmake/ProcessOptions.cmake
@@ -421,7 +421,7 @@ function( NEST_PROCESS_WITH_PYTHON )
       set( Python_INCLUDE_DIRS "${Python_INCLUDE_DIRS}" PARENT_SCOPE )
       set( Python_LIBRARIES "${Python_LIBRARIES}" PARENT_SCOPE )
 
-      if ( cythonize-pynest )
+      if ( BUILD_PYTHON AND cythonize-pynest )
         # Need updated Cython because of a change in the C api in Python 3.7
         find_package( Cython 0.28.3 REQUIRED )
         if ( CYTHON_FOUND )
