--- config.c.orig	Fri Jan 24 15:26:47 2003
+++ config.c	Fri Jan 24 15:31:42 2003
@@ -3978,7 +3978,7 @@
     areasort();
     group_build_arealist();
     printf (" \n");
-    InitScreen();
+    InitScreen(0);
     mygetcwd(tmp, PATHLEN);
     ST->home = xstrdup(tmp);
 
@@ -4003,6 +4003,5 @@
 
     WndClose(hWnd);
     WndCurr(hCurr);
-    TTScolor(cm[CM_NTXT]);
-    TTClear(hMnScr->x1, hMnScr->y1, hMnScr->x2, hMnScr->y2);
+    InitScreen(1);
 }
