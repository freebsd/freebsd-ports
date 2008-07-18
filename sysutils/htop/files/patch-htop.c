--- htop.c.orig	2008-04-27 13:56:38.000000000 +0800
+++ htop.c	2008-07-16 12:54:44.000000000 +0800
@@ -110,9 +110,11 @@
    mvaddstr(15, 0, "   F9 k: kill process/tagged processes      P: sort by CPU%");
    mvaddstr(16, 0, " + [ F7: lower priority (+ nice)            M: sort by MEM%");
    mvaddstr(17, 0, " - ] F8: higher priority (root only)        T: sort by TIME");
+#if 0
    if (pl->processorCount > 1)
       mvaddstr(18, 0, "      a: set CPU affinity                F4 I: invert sort order");
    else
+#endif
       mvaddstr(18, 0, "                                         F4 I: invert sort order");
    mvaddstr(19, 0, "   F2 S: setup                           F6 >: select sort column");
    mvaddstr(20, 0, "   F1 h: show this help screen");
@@ -129,8 +131,10 @@
    mvaddstr(16, 0, " + [ F7"); mvaddstr(16,40, "    M");
    mvaddstr(17, 0, " - ] F8"); mvaddstr(17,40, "    T");
                                mvaddstr(18,40, " F4 I");
+#if 0
    if (pl->processorCount > 1)
       mvaddstr(18, 0, "      a:");
+#endif
    mvaddstr(19, 0, "   F2 S"); mvaddstr(19,40, " F6 >");
    mvaddstr(20, 0, "   F1 h");
    mvaddstr(21, 0, "  F10 q"); mvaddstr(21,40, "    s");
@@ -625,6 +629,7 @@
          refreshTimeout = 0;
          break;
       }
+#if 0
       case 'a':
       {
          if (pl->processorCount == 1)
@@ -660,6 +665,7 @@
          refreshTimeout = 0;
          break;
       }
+#endif
       case KEY_F(10):
       case 'q':
          quit = 1;
