--- areas.c.orig	Fri Jan 24 15:07:44 2003
+++ areas.c	Fri Jan 24 15:09:38 2003
@@ -739,7 +739,6 @@
 
         TTBeginOutput();
         WndClearLine(0, cm[MN_NTXT]);
-        WndClearLine(maxy - 1, cm[MN_NTXT]);
         hCurr = WndTop();
         hWnd = WndOpen(0, 1, wid, dep, NBDR | NOSAVE, 0, cm[MN_BTXT]);
         WndBox(0, 0, maxx - 1, maxy - 3, cm[MN_BTXT], SBDR);
@@ -796,7 +795,6 @@
     dep = maxy - 2;
 
     WndClearLine(0, cm[MN_NTXT]);
-    WndClearLine(maxy - 1, cm[MN_NTXT]);
     hCurr = WndTop();
     hWnd = WndOpen(0, 1, wid, dep, NBDR, 0, cm[MN_BTXT]);
     WndBox(0, 0, maxx - 1, maxy - 3, cm[MN_BTXT], SBDR);
