- math/arpack++ installs headers into include/ARPACK++, not include/arpack++

--- cmake/modules/FindARPACKPP.cmake.orig	2021-01-16 23:52:06 UTC
+++ cmake/modules/FindARPACKPP.cmake
@@ -32,14 +32,14 @@ find_package(ARPACK)
 find_path(ARPACKPP_INCLUDE_DIR
   NAMES "arssym.h"
   PATHS ${ARPACKPP_PREFIX} ${ARPACKPP_ROOT}
-  PATH_SUFFIXES "include" "include/arpack++"
+  PATH_SUFFIXES "include" "include/ARPACK++"
   NO_DEFAULT_PATH
 )
 
 # look for header files, including default paths
 find_path(ARPACKPP_INCLUDE_DIR
   NAMES "arssym.h"
-  PATH_SUFFIXES "include" "include/arpack++"
+  PATH_SUFFIXES "include" "include/ARPACK++"
 )
 
 # The arpack++ package in Debian also includes a shared library that we have
