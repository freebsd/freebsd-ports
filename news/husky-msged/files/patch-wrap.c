--- ./wrap.c.orig	Fri Jan 24 15:26:18 2003
+++ ./wrap.c	Fri Jan 24 15:26:35 2003
@@ -2357,7 +2357,7 @@
     /* Redraw the screen. */
 
     cursor(0);
-    InitScreen();
+    InitScreen(1);
     BuildHotSpots();
     DrawHeader();
     ShowNewArea();
