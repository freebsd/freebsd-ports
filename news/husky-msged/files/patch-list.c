--- list.c.orig	Fri Jan 24 15:01:23 2003
+++ list.c	Fri Jan 24 15:04:28 2003
@@ -639,7 +639,6 @@
 
     TTBeginOutput();
     WndClearLine(0, cm[MN_NTXT]);
-    WndClearLine(maxy - 1, cm[MN_NTXT]);
     WndWriteStr(2, 0, cm[LS_TTXT], CurArea.description);
     hCurr = WndTop();
     hWnd = WndOpen(0, 1, maxx - 1, maxy - 2, NBDR | NOSAVE, 0, cm[LS_NTXT]);
