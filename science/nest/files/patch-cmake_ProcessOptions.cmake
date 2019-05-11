--- cmake/ProcessOptions.cmake.orig	2019-05-11 20:18:03 UTC
+++ cmake/ProcessOptions.cmake
@@ -385,7 +385,7 @@ function( NEST_PROCESS_WITH_PYTHON )
             # confirmed working: 0.19.2+
             # in between unknown
             if ( CYTHON_VERSION VERSION_LESS "0.19.2" )
-              message( FATAL_ERROR "Your Cython version is too old. Please install "
+              message( FATAL_ERROR "Your Cython version (" ${CYTHON_VERSION} ") is too old. Please install "
                                    "newer version (0.19.2+)" )
             endif ()
 
