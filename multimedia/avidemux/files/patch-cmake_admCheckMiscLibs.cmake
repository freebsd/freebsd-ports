--- cmake/admCheckMiscLibs.cmake.orig	2019-12-14 18:40:01 UTC
+++ cmake/admCheckMiscLibs.cmake
@@ -69,7 +69,7 @@ ENDIF (UNIX AND NOT APPLE)
 MESSAGE(STATUS "Checking for execinfo")
 MESSAGE(STATUS "*********************")
 
-FIND_HEADER_AND_LIB(EXECINFO execinfo.h c backtrace_symbols)
+FIND_HEADER_AND_LIB(EXECINFO execinfo.h execinfo backtrace_symbols)
 PRINT_LIBRARY_INFO("execinfo" EXECINFO_FOUND "${EXECINFO_INCLUDE_DIR}" "${EXECINFO_LIBRARY_DIR}")
 
 IF (EXECINFO_INCLUDE_DIR)
