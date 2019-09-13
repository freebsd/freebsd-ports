--- macros/curses.m4.orig	2006-03-09 19:44:48 UTC
+++ macros/curses.m4
@@ -182,6 +182,12 @@ AC_DEFUN([AC_SEARCH_CURSES_H], [
 	if test "x$curses_location" != "xfalse"
 	then
 		dnl  check this particular location
+		AC_SEARCH_CURSES_FILE($curses_location/include, ncurses/ncurses.h, 
+					-L$curses_location/lib -lncursesw, 
+					-I$curses_location/include )
+		AC_SEARCH_CURSES_FILE($curses_location/include, ncurses.h, 
+					-L$curses_location/lib -lncursesw, 
+					-I$curses_location/include )
 		AC_SEARCH_CURSES_FILE($curses_location/include, ncursesw/ncurses.h, 
 					-L$curses_location/lib -lncursesw, 
 					-I$curses_location/include )
