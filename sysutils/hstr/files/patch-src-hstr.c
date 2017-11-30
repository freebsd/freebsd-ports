--- src/hstr.c.orig	2017-09-30 10:01:44 UTC
+++ src/hstr.c
@@ -22,6 +22,8 @@
 #include <locale.h>
 #ifdef __APPLE__
 #include <curses.h>
+#elif defined(__FreeBSD__)
+#include <ncurses.h>
 #else
 #include <ncursesw/curses.h>
 #endif
