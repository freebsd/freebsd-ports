--- cmake/modules/FindHUNSPELL.cmake.orig	2012-04-10 20:15:53 UTC
+++ cmake/modules/FindHUNSPELL.cmake
@@ -9,7 +9,8 @@
 #Based on examples at http://www.vtk.org/Wiki/CMake:How_To_Find_Libraries
 
 FIND_PATH(HUNSPELL_INCLUDE_DIR hunspell/hunspell.hxx )
-FIND_LIBRARY(HUNSPELL_LIBRARIES NAMES hunspell-1.3 hunspell-1.2 PATHS /opt/local/lib /usr/local/lib /usr/lib )
+FIND_LIBRARY(HUNSPELL_LIBRARIES NAMES hunspell-1.5 hunspell-1.4 hunspell-1.3 hunspell-1.2
+  PATHS /opt/local/lib /usr/local/lib /usr/lib )
 
 INCLUDE(FindPackageHandleStandardArgs)
 # handle the QUIETLY and REQUIRED arguments and set HUNSPELL_FOUND to TRUE
