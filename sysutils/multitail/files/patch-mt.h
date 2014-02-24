--- mt.h.orig	2014-02-16 09:06:54.000000000 -0500
+++ mt.h	2014-02-24 14:32:20.000000000 -0500
@@ -49,8 +49,13 @@
 #endif
 
 #ifdef UTF8_SUPPORT
-	#include <ncursesw/panel.h>
-	#include <ncursesw/ncurses.h>
+	#if defined(__FreeBSD__)
+	    #include <panel.h>
+	    #include <curses.h>
+	#else
+	    #include <ncursesw/panel.h>
+	    #include <ncursesw/ncurses.h>
+	#endif
 #else
 	#if defined(sun) || defined(__sun) || defined(scoos) || defined(_HPUX_SOURCE) || defined(AIX) || defined(__CYGWIN__)
 		#include <ncurses/panel.h>
