--- source/scott.c.orig	Fri Aug  6 17:45:27 2004
+++ source/scott.c	Fri Aug  6 17:47:15 2004
@@ -364,6 +364,7 @@
 		mvwaddstr(main_win, 1, 0, buf);
 	}
 #endif
+		break;
 	}
 #if 0
 	wrefresh(main_win);
