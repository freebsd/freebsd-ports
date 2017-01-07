--- cmake/FindHUNSPELL.cmake.orig	2016-12-03 21:15:34 UTC
+++ cmake/FindHUNSPELL.cmake
@@ -14,7 +14,8 @@ ENDIF (HUNSPELL_INCLUDE_DIR AND HUNSPELL
 
 FIND_PATH(HUNSPELL_INCLUDE_DIR hunspell/hunspell.hxx )
 
-FIND_LIBRARY(HUNSPELL_LIBRARIES NAMES hunspell-1.5 hunspell-1.4 hunspell-1.3 hunspell-1.2)
+FIND_LIBRARY(HUNSPELL_LIBRARIES NAMES hunspell-1.6
+             hunspell-1.5 hunspell-1.4 hunspell-1.3 hunspell-1.2 hunspell)
 
 # handle the QUIETLY and REQUIRED arguments and set HUNSPELL_FOUND to TRUE if 
 # all listed variables are TRUE
