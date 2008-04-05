--- ./src/powerflute.c.orig	2008-04-05 15:12:15.000000000 +0300
+++ ./src/powerflute.c	2008-04-05 15:12:29.000000000 +0300
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
