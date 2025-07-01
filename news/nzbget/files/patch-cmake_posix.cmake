--- cmake/posix.cmake.orig	2025-07-01 18:02:31 UTC
+++ cmake/posix.cmake
@@ -81,9 +81,6 @@ else()
 
 	if(NOT DISABLE_CURSES)
 		set(CURSES_NEED_NCURSES TRUE)
-		if(NOT APPLE)
-			set(CURSES_NEED_WIDE TRUE)
-		endif()
 		find_package(Curses REQUIRED)
 		set(INCLUDES ${INCLUDES} ${CURSES_INCLUDE_DIRS})
 		set(LIBS ${LIBS} ${CURSES_LIBRARIES})
