--- cmake/posix.cmake.orig	2024-11-19 07:09:42 UTC
+++ cmake/posix.cmake
@@ -93,7 +93,6 @@ else()
 
 	if(NOT DISABLE_CURSES)
 		set(CURSES_NEED_NCURSES TRUE)
-		set(CURSES_NEED_WIDE TRUE)
 		find_package(Curses REQUIRED)
 		set(INCLUDES ${INCLUDES} ${CURSES_INCLUDE_DIRS})
 		set(LIBS ${LIBS} ${CURSES_LIBRARIES})
