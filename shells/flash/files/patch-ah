--- modules/alarms.c.orig	Mon Jan 22 06:23:11 2001
+++ modules/alarms.c	Fri Jan 26 05:28:01 2001
@@ -1,9 +1,17 @@
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
-#include <wchar.h>
 #include <unistd.h>
 #include <termios.h>
 #include <syslog.h>
