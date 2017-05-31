--- ttyclock.c.orig	2009-06-17 18:07:38 UTC
+++ ttyclock.c
@@ -174,19 +174,19 @@ update_hour(void)
 }
 
 void
-draw_number(int n, int x, int y)
+draw_number(int n, int y, int x)
 {
-     int i, sy = y;
+     int i, sx = x;
 
-     for(i = 0; i < 30; ++i, ++sy)
+     for(i = 0; i < 30; ++i, ++sx)
      {
-          if(sy == y + 6)
+          if(sx == x + 6)
           {
-               sy = y;
-               ++x;
+               sx = x;
+               ++y;
           }
           wbkgdset(ttyclock->framewin, COLOR_PAIR(number[n][i/2]));
-          mvwaddch(ttyclock->framewin, x, sy, ' ');
+          mvwaddch(ttyclock->framewin, y, sx, ' ');
      }
      wrefresh(ttyclock->framewin);
 
@@ -209,11 +209,6 @@ draw_clock(void)
      draw_number(ttyclock->date.minute[0], 1, 20);
      draw_number(ttyclock->date.minute[1], 1, 27);
 
-     /* Draw the date */
-     wbkgdset(ttyclock->datewin, (COLOR_PAIR(2)));
-     mvwprintw(ttyclock->datewin, (DATEWINH / 2), 1, ttyclock->date.datestr);
-     wrefresh(ttyclock->datewin);
-
      /* Draw second if the option is enable */
      if(ttyclock->option.second)
      {
@@ -227,6 +222,11 @@ draw_clock(void)
           draw_number(ttyclock->date.second[1], 1, 46);
      }
 
+     /* Draw the date */
+     wbkgdset(ttyclock->datewin, (COLOR_PAIR(2)));
+     mvwprintw(ttyclock->datewin, (DATEWINH / 2), 1, ttyclock->date.datestr);
+     wrefresh(ttyclock->datewin);
+
      return;
 }
 
