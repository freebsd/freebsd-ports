--- xutils.c.orig	2015-12-06 01:59:53 UTC
+++ xutils.c
@@ -52,6 +52,12 @@ char		*Geometry = "";
 XpmIcon		wmgen;
 Pixmap		pixmask;
 
+Display		*display;
+Window          Root;
+Window          iconwin, win;
+int             screen; 
+int             DisplayDepth;
+GC NormalGC;
 
 
 
