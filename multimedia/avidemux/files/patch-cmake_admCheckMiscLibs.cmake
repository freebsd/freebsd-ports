--- cmake/admCheckMiscLibs.cmake.orig	2015-05-30 14:09:29 UTC
+++ cmake/admCheckMiscLibs.cmake
@@ -67,7 +67,7 @@ ENDIF (UNIX AND NOT APPLE)
 MESSAGE(STATUS "Checking for execinfo")
 MESSAGE(STATUS "*********************")
 
-FIND_HEADER_AND_LIB(execinfo execinfo.h execinfo backtrace_symbols)
+FIND_HEADER_AND_LIB(EXECINFO execinfo.h execinfo backtrace_symbols)
 PRINT_LIBRARY_INFO("execinfo" EXECINFO_FOUND "${LIBEXECINFO_INCLUDE_DIR}" "${LIBEXECINFO_LIBRARY_DIR}")
 
 IF (LIBEXECINFO_INCLUDE_DIR)
