--- ./nshow.c.orig	Thu Jun 21 03:21:35 2001
+++ ./nshow.c	Fri Jan 24 15:35:24 2003
@@ -36,7 +36,7 @@
 int groupmove = 0;
 HotGroup Hot;
 
-int InitScreen(void)
+int InitScreen(int draw_statbar)
 {
     if (SW->usemouse == NO)
     {
@@ -56,6 +56,8 @@
     else
         maxy = term.NRow;
     hMnScr = WndOpen(0, 0, maxx - 1, maxy - 1, NBDR, 0, cm[CM_NTXT]);
+    if (draw_statbar && SW->statbar)
+	    WndClearLine(maxy - 1, cm[CM_ITXT]);
     SW->redraw = TRUE;
     return 0;
 }
@@ -468,7 +470,6 @@
         if (l - 2 < maxx - 1)
             WndPutsn(l - 2, maxy - 1, (maxx - 1) - (l - 2),
                      cm[CM_ITXT] | F_ALTERNATE, line + (l - 2));
-        WndClear(maxx - 1, maxy - 1, maxx - 1, maxy - 1,  cm[CM_ITXT]); 
     }
     if (!m)
     {
