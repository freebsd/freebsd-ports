--- modules/background.c	Sat Oct 25 11:34:23 1997
+++ modules/background.c.new	Sun Jan  2 20:48:46 2000
@@ -20,8 +20,17 @@
 
 	  */
 
+#ifdef HAVE_CONFIG_H
+#include "../config.h"
+#endif
+
+#ifdef HAVE_NCURSES_NCURSES_H
+#include <ncurses/ncurses.h>
+#include <ncurses/term.h>
+#else
 #include <curses.h>
 #include <term.h>
+#endif
 
 #include <stdlib.h>
 #include <stdio.h>
