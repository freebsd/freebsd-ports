We fetch 3.4 (since 3.5 breaks it), we don't want it to find
system antlr3 (3.5) and overwrite our fetched one

--- cmake/FindANTLR.cmake.orig	2019-04-09 16:14:31 UTC
+++ cmake/FindANTLR.cmake
@@ -27,7 +27,6 @@ find_library(ANTLR_LIBRARIES
   NO_DEFAULT_PATH)
 
 if(CHECK_SYSTEM_VERSION)
-  find_program(ANTLR_BINARY NAMES antlr3)
   find_path(ANTLR_INCLUDE_DIR NAMES antlr3.h)
   find_library(ANTLR_LIBRARIES NAMES antlr3c)
 endif()
