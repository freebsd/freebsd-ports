--- mt.h.orig	2019-11-09 18:07:35 UTC
+++ mt.h
@@ -60,8 +60,13 @@ typedef enum { SCHEME_TYPE_EDIT = 0, SCHEME_TYPE_FILTE
 #endif
 
 #if defined(UTF8_SUPPORT) && !defined(__APPLE__)
-	#include <ncursesw/panel.h>
-	#include <ncursesw/ncurses.h>
+	#if defined(__FreeBSD__)
+		#include <panel.h>
+		#include <curses.h>
+	#else
+		#include <ncursesw/panel.h>
+		#include <ncursesw/ncurses.h>
+	#endif
 #else
 	#if defined(__APPLE__)
         #include <ncurses.h>
