--- cmake/posix.cmake.orig	2025-09-14 16:13:35 UTC
+++ cmake/posix.cmake
@@ -82,9 +82,6 @@ else()
 
 	if(NOT DISABLE_CURSES)
 		set(CURSES_NEED_NCURSES TRUE)
-		if(NOT APPLE)
-			set(CURSES_NEED_WIDE TRUE)
-		endif()
 		find_package(Curses REQUIRED)
 		set(INCLUDES ${INCLUDES} ${CURSES_INCLUDE_DIRS})
 		set(LIBS ${LIBS} ${CURSES_LIBRARIES})
