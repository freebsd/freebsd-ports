--- modules/countdown.c	Wed Oct 29 13:42:28 1997
+++ modules/countdown.c.new	Sun Jan  2 20:50:16 2000
@@ -4,8 +4,17 @@
 
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
