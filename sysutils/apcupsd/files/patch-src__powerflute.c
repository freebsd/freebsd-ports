--- ./src/powerflute.c.orig	2008-01-27 18:22:57.000000000 +0200
+++ ./src/powerflute.c	2008-06-29 14:16:28.000000000 +0300
@@ -28,12 +28,12 @@
 #ifdef HAVE_POWERFLUTE
 
 #ifdef HAVE_NCURSES_MENU_H
-# include <ncurses/curses.h>
+# include <ncurses/ncurses.h>
 # include <ncurses/panel.h>
 # include <ncurses/menu.h>
 #else
 # ifdef HAVE_MENU_H
-#  include <curses.h>
+#  include <ncurses.h>
 #  include <panel.h>
 #  include <menu.h>
 # else
