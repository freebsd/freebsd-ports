--- src/include/hstr_curses.h.orig	2017-09-30 10:01:44 UTC
+++ src/include/hstr_curses.h
@@ -21,6 +21,8 @@
 
 #ifdef __APPLE__
 #include <curses.h>
+#elif defined(__FreeBSD__)
+#include <ncurses.h>
 #else
 #include <ncursesw/curses.h>
 #endif
