--- cmake/FindCURSES.cmake.orig	2021-11-02 19:09:25 UTC
+++ cmake/FindCURSES.cmake
@@ -58,7 +58,11 @@ if(NCURSES_NOT_FOUND EQUAL -1)
     set(HAVE_LIBNCURSES 1)
     set(CURSES_INCLUDE "<ncurses.h>")
 
-    set(CURSES_LIBRARY ${PC_NCurses_LINK_LIBRARIES})
+    find_library(CURSES_LIBRARY
+      NAMES ncurses
+      PATHS ${PC_NCurses_LIBRARY_DIRS}
+    )
+
     set(CURSES_VERSION ${PC_NCurses_VERSION})
 
     include(FindPackageHandleStandardArgs)
