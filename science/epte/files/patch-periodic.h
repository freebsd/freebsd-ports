--- periodic.h.orig	2010-09-01 10:31:23.665697651 +0200
+++ periodic.h	2010-09-01 10:48:57.742657991 +0200
@@ -296,7 +296,7 @@ modification follow.
 #ifdef VMS
 #include <curses.h>
 #endif
-#if defined(linux) || defined(__FreeBSD)
+#if defined(linux) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <ncurses.h>
 #endif
 
