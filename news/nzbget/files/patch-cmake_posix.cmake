--- cmake/posix.cmake.orig	2024-12-05 05:22:43 UTC
+++ cmake/posix.cmake
@@ -93,9 +93,6 @@ else()
 
 	if(NOT DISABLE_CURSES)
 		set(CURSES_NEED_NCURSES TRUE)
-		if(NOT APPLE)
-			set(CURSES_NEED_WIDE TRUE)
-		endif()
 		find_package(Curses REQUIRED)
 		set(INCLUDES ${INCLUDES} ${CURSES_INCLUDE_DIRS})
 		set(LIBS ${LIBS} ${CURSES_LIBRARIES})
