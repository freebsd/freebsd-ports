--- ./msged.c.orig	Tue Nov 27 01:13:44 2001
+++ ./msged.c	Fri Jan 24 15:35:36 2003
@@ -1863,7 +1863,7 @@
     fputs("\nEnter the command \"EXIT\" to return to " PROG ".\n", stderr);
     shell_to_dos();
     cursor(0);
-    InitScreen();
+    InitScreen(1);
     BuildHotSpots();
     DrawHeader();
     ShowNewArea();
@@ -2017,7 +2017,7 @@
         WndClose(hMnScr);
         KillHotSpots();
         TTclose();
-        InitScreen();
+        InitScreen(1);
         adapt_margins();
         BuildHotSpots();
         ShowNewArea();
